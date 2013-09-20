# $FreeBSD$

PORTNAME=	subweb
PORTVERSION=	1.0
CATEGORIES=	security www
MASTER_SITES=	http://www.hsc.fr/ressources/outils/subweb/download/

MAINTAINER=	ecu@200ok.org
COMMENT=	SubWeb is a (reverse) proxy to inspect HTTP flows on the fly

NO_BUILD=	YES

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/subweb ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/subweb
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/subweb
.endif

.include <bsd.port.mk>
