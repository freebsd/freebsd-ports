PORTNAME=	dovi_tool
DISTVERSION=	2.1.2
PORTREVISION=	7
CATEGORIES=	multimedia

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Tool combining multiple utilities for working with Dolby Vision
WWW=		https://github.com/quietvoid/dovi_tool

LICENSE=	MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	quietvoid

CARGO_FEATURES=	--no-default-features \
	internal-font

PLIST_FILES=	bin/dovi_tool

.include <bsd.port.mk>
