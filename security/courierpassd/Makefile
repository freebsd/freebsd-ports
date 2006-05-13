# New ports collection makefile for:	courierpassd
# Date created:				26th July 2005
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	courierpassd
PORTVERSION=	1.1.0
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/store/

MAINTAINER=	ade@FreeBSD.org
COMMENT=	User authentication and password changing daemon utility

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}' LDFLAGS='${LDFLAGS}'

MINUID?=	100
DELAY?=		3
CONFIGURE_ARGS+=--with-minuid=${MINUID} --with-badpassdelay=${DELAY}

PLIST_FILES=	sbin/courierpassd
MAN8=		courierpassd.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
