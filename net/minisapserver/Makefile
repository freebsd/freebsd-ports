# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	minisapserver
PORTVERSION=	0.3.8
CATEGORIES=	net multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/miniSAPserver/${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	SAP and SLP announcement for the VLC Media Player

LICENSE=	GPLv2

USES=		iconv tar:xz
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/sapserver etc/sap.cfg-dist man/man1/sapserver.1.gz
USE_RC_SUBR=	sapserver
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SLP
SLP_DESC=	Enable SLP support via openslp

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SLP_LIB_DEPENDS=	libslp.so:net/openslp
SLP_CONFIGURE_ENABLE=	slp

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/share/man|${MANPREFIX}/man|; \
		s|$$(prefix)/share/doc/sapserver|${DOCSDIR}|; \
		s|sap.cfg|sap.cfg-dist|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|XFLAGS="-Wall|XFLAGS="${CXXFLAGS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/sap.cfg|${PREFIX}/etc/sap.cfg|' \
		${WRKSRC}/sapserver.h
	@${REINPLACE_CMD} -e 's|a6->sin_len|a6->sin6_len|g' ${WRKSRC}/broadcast.cpp
	@${CP} -f ${WRKSRC}/sap.cfg ${WRKSRC}/sap.cfg-dist

.include <bsd.port.mk>
