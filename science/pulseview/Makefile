# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	pulseview
PORTVERSION=	0.2.0
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/pulseview/

MAINTAINER=	uffe@uffe.org
COMMENT=	GUI client that supports various hardware logic analyzers

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libsigrok.so:${PORTSDIR}/devel/libsigrok \
		libsigrokdecode.so:${PORTSDIR}/devel/libsigrokdecode

USES=		cmake gmake pkgconfig
USE_QT4=	corelib gui moc qmake rcc uic
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man
PLIST_FILES=	bin/pulseview man/man1/pulseview.1.gz

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
