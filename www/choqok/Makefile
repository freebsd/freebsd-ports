# New ports collection makefile for:	Choqok
# Date created:				15 Sep 2009
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	choqok
PORTVERSION=	0.9.90
CATEGORIES=	www kde
MASTER_SITES=	http://d10xg45o6p6dbl.cloudfront.net/projects/c/choqok/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client

LICENSE=	GPLv3

LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson \
		qoauth.1:${PORTSDIR}/devel/qoauth

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
