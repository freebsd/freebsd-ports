# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	pathauto
DISTVERSION=	6.x-1.4
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically generates URLs for Drupal content

RUN_DEPENDS=	drupal6-token>=0:${PORTSDIR}/www/drupal6-token

USE_DRUPAL=	yes
DRUPAL6_MODULE=	yes
MODULE_FILES=	pathauto.admin.inc pathauto.inc pathauto.info \
		pathauto.install pathauto.js pathauto.module \
		pathauto_node.inc pathauto_taxonomy.inc pathauto_user.inc \
		pathauto.api.php pathauto.test \
		translations/pathauto.pot translations/ar.po translations/cs.po \
		translations/da.po translations/de.po translations/el.po \
		translations/es.po translations/fr.po translations/ja.po \
		translations/nl.po translations/ru.po translations/tr.po
MODULE_DIRS=	translations

DOC_FILES=	INSTALL.txt API.txt README.txt i18n-ascii.example.txt \
		LICENSE.txt

.include <bsd.port.mk>
