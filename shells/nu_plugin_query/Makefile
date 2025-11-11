PORTNAME=	nu_plugin_query
DISTVERSION=	${NUSHELL_VER}
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	https://crates.io/api/v1/crates/${PORTNAME}/${DISTVERSION}/download?dummy=/:main
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nushell plugin: Querying SQL, XML, JSON, HTML, and WebPage Metadata
WWW=		https://www.nushell.sh/

LICENSE=	MIT

BROKEN_FreeBSD_15_armv7=	compilation fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282712

USES=		cargo ssl

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

.include <../nushell/Makefile.version>
.include <bsd.port.mk>
