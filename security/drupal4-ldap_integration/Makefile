# New ports collection makefile for:	drupal-ldap_integration
# Date created:				12 January 2006
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldap_integration
DISTVERSION=	${DRUPAL_VERSION}
PORTREVISION=	20060117
CATEGORIES=	security www

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LDAP user authentication for the Drupal CMS

USE_PHP=	ldap

BROKEN=		Install fails

DRUPAL_MODULE=	yes
MODULE_FILES=	ldap_integration.module \
		ldap_integration/LDAPInterface.php \
		zcallbacks.module
MODULE_CONF_FILES=	ldap_integration/conf.php
MODULE_CONF_DIRS=	ldap_integration
DOC_FILES=	CHANGES.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
