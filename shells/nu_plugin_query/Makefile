PORTNAME=	nu_plugin_query
DISTVERSION=	${NUSHELL_VER}
CATEGORIES=	shells
MASTER_SITES=	https://crates.io/api/v1/crates/${PORTNAME}/${DISTVERSION}/download?dummy=/:main
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nushell plugin: Querying SQL, XML, JSON, HTML, and WebPage Metadata
WWW=		https://www.nushell.sh/

LICENSE=	MIT

USES=		cargo ssl

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

.include <../nushell/Makefile.version>
.include <bsd.port.mk>
