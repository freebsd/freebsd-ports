# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgringotts
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	BERLIOS/gringotts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for encapsulating/safekeeping data in encrypted/compressed form

LIB_DEPENDS=	libmcrypt.so:${PORTSDIR}/security/libmcrypt \
		libmhash.so:${PORTSDIR}/security/mhash

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-pkg-config-files=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|md5sum|md5|g" ${WRKSRC}/Makefile.in

pre-install:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E "s|^(libgringottsdocdir =).*|\1 $$\(datadir\)/doc/libgringotts|" ${WRKSRC}/docs/Makefile ${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -E -e "s|^(SUBDIRS =.*) docs|\1|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e "s|^(install-data-am:.*)install-libgringottsdocDATA|\1|" ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
