# New ports collection makefile for:	apache-xml-security-c
# Date created:				06 Febuary 2007
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	xml-security-c
PORTVERSION=	1.6.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=santuario/c-library
PKGNAMEPREFIX=	apache-

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Apache XML security libraries C version

OPTIONS=	XERCES_DEVEL	"With Xerces vesion 2.8 (shibboleth2 requires)" on

USE_OPENSSL=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_XERCES_DEVEL)
LIB_DEPENDS+=	xerces-c.28:${PORTSDIR}/textproc/xerces-c2-devel
.else
LIB_DEPENDS+=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.include <bsd.port.post.mk>
