PORTNAME=	openvanilla-framework
PORTVERSION=	0.7.2.20070514
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development header files for OpenVanilla

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/OpenVanilla
	${INSTALL_DATA} ${WRKSRC}/Framework/Headers/* \
		${STAGEDIR}${PREFIX}/include/OpenVanilla

.include <bsd.port.mk>
