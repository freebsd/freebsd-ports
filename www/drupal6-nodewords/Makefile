# New ports collection makefile for:	drupal6-nodewords
# Date created:				08 Nov 2008
# Whom:					Nick Hilliard <nick@netability.ie>
#
# $FreeBSD$
#

PORTNAME=	nodewords
DISTVERSION=	6.x-1.11
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	A drupal module which allows the end-user to set meta tags for nodes

DRUPAL6_MODULE=	yes
MODULE_DIRS=	nodewords_basic/translations nodewords_basic \
		nodewords_extra/translations nodewords_extra includes \
		nodewords_verification_tags/translations \
		nodewords_verification_tags translations
MODULE_FILES=	includes/forum.inc includes/image.inc includes/node.inc \
		includes/taxonomy.inc includes/taxonomy_menu.inc \
		includes/tracker.inc includes/uc_catalog.inc \
		includes/user.inc nodewords.admin.inc nodewords.api.php \
		nodewords.info nodewords.install nodewords.module \
		nodewords.test nodewords_basic/nodewords_basic.info \
		nodewords_basic/nodewords_basic.install \
		nodewords_basic/nodewords_basic.module \
		nodewords_basic/translations/nodewords_basic.de.po \
		nodewords_basic/translations/nodewords_basic.pot \
		nodewords_extra/nodewords_extra.info \
		nodewords_extra/nodewords_extra.install \
		nodewords_extra/nodewords_extra.module \
		nodewords_extra/translations/nodewords_extra.de.po \
		nodewords_extra/translations/nodewords_extra.pot \
		nodewords_verification_tags/nodewords_verification_tags.info \
		nodewords_verification_tags/nodewords_verification_tags.install \
		nodewords_verification_tags/nodewords_verification_tags.module \
		nodewords_verification_tags/translations/nodewords_verification_tags.de.po \
		nodewords_verification_tags/translations/nodewords_verification_tags.pot \
		translations/nodewords.de.po translations/nodewords.fr.po \
		translations/nodewords.hu.po translations/nodewords.ja.po \
		translations/nodewords.pot translations/nodewords.ru.po

DOC_FILES=	README.txt CHANGELOG.txt API.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
