# New ports collection makefile for:	libnetdude
# Date created:		2004-04-23
# Whom:			Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	libnetdude
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netdude

MAINTAINER=	yb@bashibuzuk.net
COMMENT=	A library for manipulating libpcap/tcpdump trace files

LIB_DEPENDS=	pcapnav.0:${PORTSDIR}/net/libpcapnav

USE_INC_LIBTOOL_VER=	13
USE_GNOME=	glib12
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${DOCSDIR}
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 500000
	@${REINPLACE_CMD} -e "s|netinet/if_fddi.h|net/fddi.h|g" \
	${WRKSRC}/protocols/fddi/libnd_fddi.h
.endif
	@${REINPLACE_CMD} -e 's|DOC_MODULE = libnetdude|DOC_MODULE =|' \
	${WRKSRC}/docs/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|docs||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
