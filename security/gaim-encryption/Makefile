# New ports collection makefile for:	gaim-encryption
# Date created:		2004-05-01
# Whom:		 	ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	encryption
PORTVERSION=	2.26
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@c0decafe.net
COMMENT=	Provides transparent RSA encryption as a Gaim plugin

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/gaim:configure
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim
LIB_DEPENDS=	nss3:${PORTSDIR}/security/nss

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	lthack gtk20
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-gaim=${WRKDIRPREFIX}${.CURDIR}/../../net/gaim/work/gaim* \
		--with-nspr-includes=${LOCALBASE}/include/nspr \
		--with-nspr-libs=${LOCALBASE}/lib \
		--with-nss-includes=${LOCALBASE}/include/nss/nss \
		--with-nss-libs=${LOCALBASE}/lib

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WARNING: make sure net/gaim is built with NSS support (it is, by default)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
