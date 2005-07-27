# New ports collection makefile for:	courierpassd
# Date created:				26th July 2005
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	courierpassd
PORTVERSION=	1.1.0.r1
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/store/
DISTNAME=	courierpassd-1.1.0-RC1

MAINTAINER=	ade@FreeBSD.org
COMMENT=	User authentication and password changing daemon utility

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/courierpassd-1.1.0-RC1

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_GETTEXT=	YES
USE_INC_LIBTOOL_VER=	15
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}' LDFLAGS='${LDFLAGS}'

PLIST_FILES=	sbin/courierpassd
MAN8=		courierpassd.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
