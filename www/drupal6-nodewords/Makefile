# New ports collection makefile for:	drupal6-nodewords
# Date created:				08 Nov 2008
# Whom:					Nick Hilliard <nick@netability.ie>
#
# $FreeBSD$
#

PORTNAME=	nodewords
DISTVERSION=	6.x-1.0
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	A drupal module which allows the end-user to set meta tags for nodes

DRUPAL6_MODULE=	yes
MODULE_DIRS=	metatags translations
MODULE_FILES=	metatags/Revisit-After.inc metatags/abstract.inc \
		metatags/copyright.inc metatags/description.inc \
		metatags/geourl.inc metatags/keywords.inc \
		metatags/robots.inc nodewords.admin.inc nodewords.info \
		nodewords.install nodewords.module translations/de.po \
		translations/fr.po translations/ja.po translations/ru.po \
		translations/nodewords.pot
DOC_FILES=	node.tpl.php-example README.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
