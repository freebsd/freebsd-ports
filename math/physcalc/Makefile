# New ports collection makefile for:	physcalc
# Date created:				Sun 27 Aug 2000
# Whom:					Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	physcalc
PORTVERSION=	2.4
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.lightlink.com/pub/vulcan/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

pre-patch:
.for FILE in compiler.h physcalc.h physconv.c physdecl.h physmain.c physmlib.c \
	     physnode.c physoper.c physsolv.c
	@${MV} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.sed
	${SED} -e 's,,,g' ${WRKSRC}/${FILE}.sed > ${WRKSRC}/${FILE} ; ${RM} ${WRKSRC}/${FILE}.sed
.endfor

pre-build:
	${PERL} -pi -e "s@void main@int main@g" ${WRKSRC}/physmain.c
	${RM} -f ${WRKSRC}/physcalc

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DSHAREDIR="\"${PREFIX}/share/physcalc/\"" -lm \
		physmain.c physconv.c physmlib.c physnode.c physoper.c physsolv.c -o physcalc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/physcalc ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/physcalc
	${INSTALL_DATA} ${WRKSRC}/*.phy ${PREFIX}/share/physcalc

.include <bsd.port.mk>
