# New ports collection makefile for:	meanwhile-gaim
# Date created:		24 June 2004
# Whom:		 	marcus@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	meanwhile
PORTVERSION=	1.2.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Provides Lotus Sametime support for Gaim

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
LIB_DEPENDS=	meanwhile.0:${PORTSDIR}/net/meanwhile
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_MW_HOST)
CONFIGURE_ARGS+=	--with-host=${WITH_MW_HOST}
.endif

.if defined(WITH_MW_PORT)
CONFIGURE_ARGS+=	--with-port=${WITH_MW_PORT}
.endif

.if defined(WITH_MW_CLIENT)
CONFIGURE_ARGS+=	--with-client=${WITH_MW_CLIENT}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_MW_HOST=host	Define the default Sametime community host server"
	@${ECHO_MSG} "	WITH_MW_PORT=port	Define the default Sametime community port (default: 1533)"
	@${ECHO_MSG} "	WITH_MW_CLIENT=client	Define the default SAmetime client identifier (default: mwLogin_MEANWHILE)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
