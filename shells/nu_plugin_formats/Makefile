PORTNAME=	nu_plugin_formats
DISTVERSION=	${NUSHELL_VER}
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	https://crates.io/api/v1/crates/${PORTNAME}/${DISTVERSION}/download?dummy=/:main
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nushell plugin: Support for several additional data formats
WWW=		https://www.nushell.sh/

LICENSE=	MIT

BROKEN_FreeBSD_15_armv7=	compilation fails, see https://github.com/nix-rust/nix/issues/2535

USES=		cargo

PLIST_FILES=	bin/${PORTNAME}

.include <../nushell/Makefile.version>
.include <bsd.port.mk>
