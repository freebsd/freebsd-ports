# New ports collection makefile for:	courierpasswd
# Date created:				23th April 2006
# Whom:					Andrew St. Jean <andrew@arda.homeunix.net>
#
# $FreeBSD$

PORTNAME=	courierpasswd
PORTVERSION=	1.1.0
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/store/

MAINTAINER=	andrew@arda.homeunix.net
COMMENT=	User authentication and password changing utility

BUILD_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}' LDFLAGS='${LDFLAGS}'

MINUID?=	100

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-minuid=${MINUID}

PLIST_FILES=	sbin/courierpasswd
MAN8=		courierpasswd.8

pre-fetch:
	@${ECHO}	""
	@${ECHO}	"#######################################################################"
	@${ECHO}	""
	@${ECHO}	"	You should set the following build option."
	@${ECHO}	""
	@${ECHO}	"	MINUID=uid	Accounts with uids below this value cannot have"
	@${ECHO}	"	their passwords changed. Default value is 100."
	@${ECHO}	""
	@${ECHO}	"#######################################################################"
	@${ECHO}	""

.include <bsd.port.mk>
