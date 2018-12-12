# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	qalculate
PORTVERSION=	2.6.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${PORTVERSION}/
DISTNAME=	${GH_PROJECT}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (GTK+3 frontend)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqalculate.so:math/libqalculate
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++11-lang gettext gmake \
		libtool:build localbase pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool libxml2

# USE_GITHUB=	Use MASTER_SITES so that the pre-rolled release is downloaded
GH_ACCOUNT=	Qalculate
GH_PROJECT=	${PORTNAME}-gtk

GNU_CONFIGURE=	yes
DATADIR=	share/${GH_PROJECT}
DOCSDIR=	share/doc/${GH_PROJECT}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
