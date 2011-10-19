# New ports collection makefile for:	x2goclient
# Date created:				2010-08-16
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	x2goclient
DISTVERSION=	3.01-5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/x2goclient/pre-git/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The x2go perl client

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-client
RUN_DEPENDS=	nxproxy:${PORTSDIR}/net/nxproxy \
		x2goclient-cli:${PORTSDIR}/net/x2goclient-cli

BROKEN=		does not compile

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
PLIST_FILES=	bin/x2goclient
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S,-5,,}
USE_QT_VER=	4
QT_COMPONENTS=	gui network svg qmake_build moc_build uic_build rcc_build
USE_OPENLDAP=	yes

post-patch:
	cd ${WRKSRC}; ${REINPLACE_CMD} -e "s,Q_OS_LINUX,Q_OS_FREEBSD," \
		embedwidget.cpp onmainwindow.cpp ongetpass.cpp \
		clicklineedit.cpp embedwidget.h clicklineedit.h
	${REINPLACE_CMD} -e "s,#include <linux/fs.h>,," \
		${WRKSRC}/onmainwindow.cpp
	${REINPLACE_CMD} -e "s,linux,freebsd," ${WRKSRC}/x2goclient.pro

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${QMAKE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/x2goclient ${PREFIX}/bin

.include <bsd.port.mk>
