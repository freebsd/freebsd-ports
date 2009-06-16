# New ports collection makefile for:	drupal6-page_title
# Date created:				2 May 2009
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	page_title
DISTVERSION=	6.x-2.0
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Drupal module to provide fine-grained control of page titles

RUN_DEPENDS=	drupal6-token>=0:${PORTSDIR}/www/drupal6-token

DRUPAL6_MODULE=	yes
MODULE_FILES=	translations/page_title.pot translations/ru.po \
		page_title-admin-settings-form.tpl.php page_title.admin.inc \
		page_title.info page_title.install page_title.module
MODULE_DIRS=	translations

DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
