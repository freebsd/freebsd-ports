# Created by: ijliao
# $FreeBSD$

PORTNAME=	libparsifal
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.saunalahti.fi/~samiuus/toni/xmlproc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight XML Parser

USES=		iconv libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|g' ${WRKSRC}/configure

post-install:
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
