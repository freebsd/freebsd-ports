# New ports collection makefile for:   vde2
# Date created:        20 January 2007
# Whom:                Philip M. Gollucci <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vde2
PORTVERSION=	2.3.2
CATEGORIES=	net
MASTER_SITES=	SF/vde/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

LICENSE=	BSD GPLv2 LGPL21
LICENSE_COMB=	multi

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=	PYTHON

CONFLICTS=	vde-[0-9]*

USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

MLINKS=		unixcmd.1 vdecmd.1 \
		vdeq.1 vdeqemu.1 \
		vdeq.1 vdekvm.1
MAN1=		dpipe.1 slirpvde.1 unixcmd.1 unixterm.1 \
		vde_autolink.1 vde_cryptcab.1 vde_l3.1 vde_over_ns.1 \
		vde_pcapplug.1 vde_plug.1 vde_plug2tap.1 vde_switch.1 \
		vdeq.1 vdetaplib.1 vdeterm.1 wirefilter.1
MAN8=		vde_tunctl.8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.else
USE_PYTHON=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	PYTHON=""
.endif

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ENV+=	V=1
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-Wall/s|-O2||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(MAKE).*install-data-hook||g' \
		${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|#AM_CFLAGS|g' \
		${WRKSRC}/src/slirpvde/Makefile.in

.include <bsd.port.post.mk>
