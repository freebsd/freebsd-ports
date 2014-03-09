# Created by: Yann Berthier <yb@sainte-barbe.org>
# $FreeBSD$

PORTNAME=	libnetdude
PORTVERSION=	0.12
CATEGORIES=	net
MASTER_SITES=	SF/netdude/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for manipulating libpcap/tcpdump trace files

LIB_DEPENDS=	pcapnav.0:${PORTSDIR}/net/libpcapnav

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib12
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${DOCSDIR}
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|netinet/if_fddi.h|net/fddi.h|g" \
	${WRKSRC}/protocols/fddi/libnd_fddi.h
	@${REINPLACE_CMD} -e 's|DOC_MODULE = libnetdude|DOC_MODULE =|' \
	${WRKSRC}/docs/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|docs||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
