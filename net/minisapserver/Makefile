# New ports collection makefile for:	minisapserver
# Date created:		2004-05-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	minisapserver
PORTVERSION=	0.3.6
CATEGORIES=	net multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/miniSAPserver/${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	SAP and SLP announcement for the VLC Media Player

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		sapserver.1
PLIST_FILES=	bin/sapserver etc/sap.cfg-dist
USE_RC_SUBR=	sapserver
SUB_FILES=	pkg-message
OPTIONS=	SLP "Enable SLP support via openslp" off

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.options.mk>

.if defined(WITH_SLP)
LIB_DEPENDS+=	slp.1:${PORTSDIR}/net/openslp

CONFIGURE_ARGS+=--enable-slp
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=--disable-slp
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.x
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
	@${CP} -f ${WRKSRC}/sap.cfg ${WRKSRC}/sap.cfg-dist

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
