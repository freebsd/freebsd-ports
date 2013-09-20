# $FreeBSD$

PORTNAME=	linuxdcpp
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://launchpadlibrarian.net/69733951/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of the DC++ Direct Connect client to Unix-like systems

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GNOME=	libglade2
USES=		iconv
USE_SCONS=	yes
USE_OPENSSL=	yes
PORTDOCS=	*

SCONS_BUILDENV=	${SCONS_ENV}

.if defined(WITH_DEBUG)
SCONS_ARGS=	debug=1
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
