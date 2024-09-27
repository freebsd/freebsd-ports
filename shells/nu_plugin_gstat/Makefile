PORTNAME=	nu_plugin_gstat
DISTVERSION=	${NUSHELL_VER}
CATEGORIES=	shells
MASTER_SITES=	https://crates.io/api/v1/crates/${PORTNAME}/${DISTVERSION}/download?dummy=/:main
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nushell plugin: Information on the status of a Git repository
WWW=		https://www.nushell.sh/

LICENSE=	MIT

LIB_DEPNDS=	libssh2.so:security/libssh2

USES=		cargo localbase ssl

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

.include <../nushell/Makefile.version>
.include <bsd.port.mk>
