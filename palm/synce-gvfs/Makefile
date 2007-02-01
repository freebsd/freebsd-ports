# New ports collection makefile for:   synce-gnomevfs
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-gnomevfs
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome VFS module for WinCE devices

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnometarget gnomevfs2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-librapi=${LOCALBASE} \
			--with-libsynce=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
