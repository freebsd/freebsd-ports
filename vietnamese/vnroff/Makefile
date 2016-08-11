# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	vnroff
PORTVERSION=	2.1
CATEGORIES=	vietnamese print
MASTER_SITES=	LOCAL/cy
DISTNAME=	${PORTNAME}-2.0
DISTFILES=	vnroff.c.Z vnroff.1.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Vietnamese VIQR text into troff format

PLIST_FILES=	bin/vnroff man/man1/vnroff.1.gz
NO_WRKSUBDIR=	yes

do-extract:
	@${RM} -rf ${WRKSRC}
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} && ${GZCAT} ${DISTDIR}/vnroff.c.Z \
		| ${SED} -e '1,/-cut here-/d' \
		> vnroff.c)
	@(cd ${WRKSRC} && ${GZCAT} ${DISTDIR}/vnroff.1.Z \
		| ${SED} -e '1,/Status:/d' \
		| ${SED} -e '1,1d' \
		| ${TR} -d '\01' \
		> vnroff.1)

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o vnroff vnroff.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnroff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vnroff.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
