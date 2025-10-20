PORTNAME=	framework-tool-tui
DISTVERSIONPREFIX=v
DISTVERSION=	0.5.5
CATEGORIES=	sysutils

MAINTAINER=	lme@FreeBSD.org
COMMENT=	TUI for Framework Computer System Utility
WWW=		https://github.com/grouzen/framework-tool-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=  	libhidapi.so:comms/hidapi
USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	grouzen

PLIST_FILES=	bin/framework-tool-tui

do-patch:
		${REINPLACE_CMD} -e s/linux/freebsd/ ${WRKSRC}/src/main.rs

.include <bsd.port.mk>
