# New ports collection makefile for:   synce-gnomevfs
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	synce-gvfs
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE-GNOME/0.13

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GVFS module for access Windows Mobile devices

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack gvfs
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
