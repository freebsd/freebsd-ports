# New ports collection makefile for:	cogibi
# Date created:				2010-08-14
# Whom:					Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cagibi
PORTVERSION=	0.1.1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/cagibi

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE SSDP/uPNP proxy

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib network xml dbus \
		qmake_build moc_build rcc_build uic_build

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
CMAKE_USE_PTHREAD=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_SUFFIX}/data/' \
		${WRKSRC}/daemon/CMakeLists.txt

.include <bsd.port.post.mk>
