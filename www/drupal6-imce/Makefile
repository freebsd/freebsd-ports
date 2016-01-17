# Created by: Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	imce
DISTVERSION=	6.x-1.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal 6.x image/file uploader module

USES=		drupal:6,module

MODULE_DIRS=	translations tpl js inc css

MODULE_FILES=	translations/uk.po \
		translations/uk-ua.po \
		translations/sv.po \
		translations/pt-br.po \
		translations/nl.po \
		translations/ja.po \
		translations/imce.pot \
		translations/hu.po \
		translations/fr.po \
		translations/fi.po \
		translations/es.po \
		translations/cs.po \
		tpl/imce-page.tpl.php \
		tpl/imce-file-list.tpl.php \
		tpl/imce-content.tpl.php \
		js/imce_set_inline.js \
		js/imce_set_app.js \
		js/imce_extras.js \
		js/imce.js \
		inc/subdir.inc \
		inc/page.inc \
		inc/js.inc \
		inc/core_profiles.inc \
		inc/admin.inc \
		imce.module \
		imce.install \
		imce.info \
		css/y-grippie.png \
		css/x-grippie.png \
		css/loading.gif \
		css/leaf.png \
		css/imce-content.css \
		css/folder.png \
		css/folder-open.png \
		css/expanded.png \
		css/collapsed.png

DOC_FILES=	README.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
