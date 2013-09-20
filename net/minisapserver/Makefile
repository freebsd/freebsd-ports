# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	minisapserver
PORTVERSION=	0.3.8
CATEGORIES=	net multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/miniSAPserver/${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	SAP and SLP announcement for the VLC Media Player

LICENSE=	GPLv2

USE_XZ=	yes
USES=	iconv
GNU_CONFIGURE=	yes
MAN1=		sapserver.1
PLIST_FILES=	bin/sapserver etc/sap.cfg-dist
USE_RC_SUBR=	sapserver
SUB_FILES=	pkg-message
OPTIONS_DEFINE=	SLP
SLP_DESC=	"Enable SLP support via openslp"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSLP}
LIB_DEPENDS+=	slp.1:${PORTSDIR}/net/openslp
CONFIGURE_ARGS+=--enable-slp
.else
CONFIGURE_ARGS+=--disable-slp
.endif

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
