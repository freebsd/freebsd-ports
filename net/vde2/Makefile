# New ports collection makefile for:   vde2
# Date created:        20 January 2007
# Whom:                Philip M. Gollucci <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vde2
PORTVERSION=	2.2.3
CATEGORIES=	net
MASTER_SITES=	SF/vde/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

CONFLICTS=	vde-[0-9]*

USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MLINKS=		unixcmd.1 vdecmd.1 \
		vdeq.1 vdeqemu.1 \
		vdeq.1 vdekvm.1
MAN1=		dpipe.1 slirpvde.1 unixcmd.1 unixterm.1 \
		vde_autolink.1 vde_cryptcab.1 vde_l3.1 vde_over_ns.1 \
		vde_pcapplug.1 vde_plug.1 vde_plug2tap.1 vde_switch.1 \
		vdeq.1 vdetaplib.1 vdeterm.1 wirefilter.1
MAN8=		vde_tunctl.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Fails to Build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(MAKE).*install-data-hook||g' \
		${WRKSRC}/man/Makefile.in

.include <bsd.port.post.mk>
