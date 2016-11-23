# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	pulseview
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/pulseview/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	GUI client that supports various hardware logic analyzers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libsigrok.so:devel/libsigrok \
		libsigrokdecode.so:devel/libsigrokdecode

USES=		cmake gmake pkgconfig
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man \
		-DDISABLE_WERROR:BOOL=TRUE
PLIST_FILES=	bin/pulseview man/man1/pulseview.1.gz

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
