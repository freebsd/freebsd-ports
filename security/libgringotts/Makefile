# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgringotts
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	BERLIOS/gringotts.berlios

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for encapsulating/safekeeping data in encrypted/compressed form

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmcrypt.so:security/libmcrypt \
		libmhash.so:security/mhash

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkg-config-files=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|md5sum|md5|g" ${WRKSRC}/Makefile.in

pre-install-DOCS-on:
	@${REINPLACE_CMD} -E "s|^(libgringottsdocdir =).*|\1 $$\(datadir\)/doc/libgringotts|" ${WRKSRC}/docs/Makefile ${WRKSRC}/Makefile

pre-install-DOCS-off:
	@${REINPLACE_CMD} -E -e "s|^(SUBDIRS =.*) docs|\1|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e "s|^(install-data-am:.*)install-libgringottsdocDATA|\1|" ${WRKSRC}/Makefile

.include <bsd.port.mk>
