# New ports collection makefile for:	drupal-ldap_integration
# Date created:				12 January 2006
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pubcookie
DISTVERSION=	${DRUPAL_VERSION}
PORTREVISION=	20060210
CATEGORIES=	www security
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Pubcookie user authentication for the Drupal CMS

RUN_DEPENDS=	${LOCALBASE}/pubcookie/keyclient:${PORTSDIR}/www/mod_pubcookie

USE_PHP=	ldap

DRUPAL_MODULE=	yes
MODULE_FILES=	pubcookie.module
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal/bsd.drupal.mk"
.include <bsd.port.post.mk>
