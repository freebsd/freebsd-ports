# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	qalculate
PORTVERSION=	1.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (GTK+3 frontend)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcln.so:math/cln \
		libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot \
		wget:ftp/wget

BROKEN_powerpc64=	fails to compile:  main.cc: undefined reference to Calculator::temporaryCategory[abi:cxx11]()

USES=		autoreconf compiler:c++11-lang gettext gmake \
		libtool:build localbase pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool libxml2
GNU_CONFIGURE=	yes
DATADIR=	share/${GH_PROJECT}
DOCSDIR=	share/doc/${GH_PROJECT}

USE_GITHUB=	yes
GH_ACCOUNT=	Qalculate
GH_PROJECT=	${PORTNAME}-gtk

.include <bsd.port.mk>
