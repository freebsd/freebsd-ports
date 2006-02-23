# New ports collection makefile for:   synce-multisync
# Date created:                September 2004
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-multisync_plugin
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	palm deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SynCE synchronisation plugin for Multisync

LIB_DEPENDS=	rra.0:${PORTSDIR}/palm/synce-rra
BUILD_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync
RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync

USE_GNOME=	gnomeprefix gnometarget gnomevfs2
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-librapi=${LOCALBASE} \
			--with-libsynce=${LOCALBASE} \
			--with-librra=${LOCALBASE} \
			--with-multisync-include=${X11BASE}/include/multisync

.include <bsd.port.mk>
