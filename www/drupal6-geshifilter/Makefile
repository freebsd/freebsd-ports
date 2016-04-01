# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	geshifilter
DISTVERSION=	6.x-1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Drupal 6 module for syntax highlighting

RUN_DEPENDS=	${LOCALBASE}/lib/php/geshi/geshi.php:devel/php5-geshi

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USES=		drupal:6,module

MODULE_DIRS=	geshi-extra tests translations
MODULE_FILES=	geshi-extra/drupal5.php geshi-extra/drupal6.php \
		geshifilter.admin.inc geshifilter.conflicts.inc \
		geshifilter.css geshifilter.filtertips.inc \
		geshifilter.inc geshifilter.info geshifilter.install \
		geshifilter.module geshifilter.pages.inc \
		geshinode.info geshinode.install geshinode.module \
		tests/geshifilter.admin.test tests/geshifilter.pages.test \
		translations/de.po translations/ja.po \
		translations/geshifilter.pot translations/sk.po

DOC_DIRS=	geshi-extra
DOC_FILES=	LICENSE.txt README.txt geshi-extra/README
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${WRKSRC}/geshifilter.inc

.include <bsd.port.mk>
