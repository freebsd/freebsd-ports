# New ports collection makefile for:   synce-gnomevfs
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	synce-gnomevfs
PORTVERSION=	0.9.0
PORTREVISION=	6
CATEGORIES=	palm
MASTER_SITES=	SF/synce

MAINTAINER=	ports@logvinov.com
COMMENT=	Gnome VFS module for WinCE devices

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnometarget gnomevfs2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-librapi=${LOCALBASE} \
			--with-libsynce=${LOCALBASE}

BROKEN=		No longer supported by developers
DEPRECATED=     ${BROKEN}
EXPIRATION_DATE=        2008-08-24

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
