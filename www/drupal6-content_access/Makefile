# Created by: Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	content_access
DISTVERSION=	6.x-1.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal 6.x Content Access module

USES=		drupal:6,module

MODULE_DIRS=	translations tests

MODULE_FILES=	tests/content_access.test \
		tests/content_access_acl.test \
		tests/content_access_test_help.php \
		content_access.admin.inc \
		content_access.css \
		content_access.info \
		content_access.install \
		content_access.module \
		content_access.rules.inc \
		translations/content_access.pot \
		translations/de.po \
		translations/sv.po

DOC_FILES=	README.txt UPGRADE.txt LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
