# New ports collection makefile for:   synce-gnomevfs
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-gnomevfs
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Gnome VFS module for WinCE devices

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2

USE_GNOME=	gnomeprefix gnometarget gnomevfs2
USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ARGS+=	--with-librapi=${LOCALBASE} \
			--with-libsynce=${LOCALBASE}

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
