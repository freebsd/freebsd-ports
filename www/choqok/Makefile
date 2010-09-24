# New ports collection makefile for:	Choqok
# Date created:				15 Sep 2009
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	choqok
PORTVERSION=	0.9.90
PORTREVISION=	2
CATEGORIES=	www kde
MASTER_SITES=	http://d10xg45o6p6dbl.cloudfront.net/projects/c/choqok/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson \
		qoauth.1:${PORTSDIR}/net/qoauth \
		kwebkit.1:${PORTSDIR}/www/kwebkitpart

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	gui network imageformats_run moc_build \
		qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
