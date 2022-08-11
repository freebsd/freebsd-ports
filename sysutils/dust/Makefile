PORTNAME=	dust
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	sysutils

MAINTAINER=	antranigv@freebsd.am
COMMENT=	More intuitive version of du

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bootandy

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
