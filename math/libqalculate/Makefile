# Created by: Sergey Akifyev <asa@agava.com>
# $FreeBSD$

PORTNAME=	libqalculate
PORTVERSION=	0.9.10
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Multi-purpose desktop calculator (backend library)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcln.so:math/cln

USES=		autoreconf gmake gettext libtool \
		localbase pathfix pkgconfig readline:port
USE_GNOME=	glib20 intltool libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	Qalculate

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|po ||g' ${WRKSRC}/Makefile.am

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
