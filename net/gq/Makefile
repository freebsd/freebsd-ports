# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gqclient

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

.if defined(WITH_OPENLDAP1)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap
.else
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2
.endif

.if !defined(WITHOUT_JPEGPHOTO)
USE_GNOME=	gdkpixbuf
.endif

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME+=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap=${LOCALBASE}

pre-configure:
	@${ECHO_MSG} "You can disable jpegPhoto attr. handling by defining WITHOUT_JPEGPHOTO=yes"
	@${ECHO_MSG}

.include <bsd.port.mk>
