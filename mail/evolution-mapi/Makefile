# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/mail/evolution-mapi/Makefile,v 1.23 2010/11/16 09:58:56 kwm Exp $

PORTNAME=	evolution-mapi
PORTVERSION=	0.32.2
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	${PKGFILES}:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	mapi.0:${PORTSDIR}/mail/libmapi
RUN_DEPENDS=	${PKGFILES}:${PORTSDIR}/mail/evolution

PKGFILES=	${LOCALBASE}/libdata/pkgconfig/evolution-plugin.pc

USE_BZIP2=	yes
USES=		gettext
USE_GMAKE=	yes
USE_GNOME=	evolutiondataserver
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

EVO_VERSION=	2.32
EDS_VERSION=	1.2
PLIST_SUB=	EVO_VERSION=${EVO_VERSION} EDS_VERSION=${EDS_VERSION}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/libexchangemapi/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.post.mk>
