# New ports collection makefile for:    wais
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $FreeBSD$
#

PORTNAME=	freeWAIS
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cnidr.org/pub/NIDR.tools/freewais/

MAINTAINER=	ports@FreeBSD.org

NO_PACKAGE=	"not yet"
NO_INSTALL=	almost
ALL_TARGET=	freebsd
MAKE_ENV:=	TOP=${WRKSRC}

is_depended: all

pre-patch:
	@${CP} ${WRKSRC}/Makefile.bsdi ${WRKSRC}/Makefile.freebsd
	@${MV} ${WRKSRC}/src/client/x/Imakefile ${WRKDIR} \
	&& ${SED} -e '\;/SETME_IN_Imakefile;s;;${WRKSRC};' \
		<${WRKDIR}/Imakefile >${WRKSRC}/src/client/x/Imakefile

.if ${MAKEFILE} != Makefile.freebsd
do-install:
	${MAKE} MAKEFILE=Makefile.freebsd do-install
.endif

.include <bsd.port.mk>
