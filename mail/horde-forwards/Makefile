# Ports collection makefile for:	forwards3
# Date created:			Mon Mar 26, 2007
# Whom:				Beech Rintoul <beech@alaskaparadise.com>
#
# $FreeBSD$
#

PORTNAME=	forwards
PORTVERSION=	3.0.1
CATEGORIES=	mail www
PKGNAMEPREFIX=	horde-
DIST_SUBDIR=	horde

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	E-mail forward

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP	if you do not need OpenLDAP;
#
# - WITHOUT_FTP	disable FTP support;
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif

.if !defined(WITHOUT_FTP)
USE_PHP+=	ftp
.endif

USE_HORDE=	base pkg-message
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES TODO

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
