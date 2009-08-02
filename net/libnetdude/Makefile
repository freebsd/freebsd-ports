# New ports collection makefile for:	libnetdude
# Date created:		2004-04-23
# Whom:			Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	libnetdude
PORTVERSION=	0.10a
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netdude

MAINTAINER=	brenton.chang@gmail.com
COMMENT=	A library for manipulating libpcap/tcpdump trace files

LIB_DEPENDS=	pcapnav.0:${PORTSDIR}/net/libpcapnav

USE_AUTOTOOLS=	libtool:22
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
