# Created by: Yann Berthier <yb@sainte-barbe.org>
# $FreeBSD$

PORTNAME=	libnetdude
PORTVERSION=	0.12
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/netdude/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating libpcap/tcpdump trace files

LIB_DEPENDS=	libpcapnav.so:${PORTSDIR}/net/libpcapnav

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --disable-static --with-html-dir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USE_AUTOTOOLS=	libltdl
USE_GNOME=	glib12
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	PORTVERSION=${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|netinet/if_fddi.h|net/fddi.h|g" \
		${WRKSRC}/protocols/fddi/libnd_fddi.h
	@${REINPLACE_CMD} -e 's|DOC_MODULE = libnetdude|DOC_MODULE =|' \
		${WRKSRC}/docs/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's,-I$$(top_srcdir)/libltdl,@INCLTDL@,' \
		-e '/LIBADD/s,$$(top_builddir)/libltdl/libltdlc.la,@LIBLTDL@,'

.include <bsd.port.mk>
