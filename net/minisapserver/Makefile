# New ports collection makefile for:	minisapserver
# Date created:		2004-05-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	minisapserver
PORTVERSION=	0.2.4
CATEGORIES=	net multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/miniSAPserver/${PORTVERSION}/
DISTNAME=	miniSAPserver-${PORTVERSION}

MAINTAINER=	ahze@ahze.net
COMMENT=	SAP and SLP announcement for the VLC Media Player

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
MAN1=		sapserver.1
PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README
PLIST_FILES=	bin/sapserver etc/sap.cfg-dist etc/rc.d/sapserver.sh
USE_RC_SUBR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
OPTIONS=	SLP "Enable SLP support via openslp" off

.if defined(WITH_SLP)
LIB_DEPENDS+=	slp.1:${PORTSDIR}/net/openslp

CONFIGURE_ARGS=	--enable-slp
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
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
	@${SED} -e 's|/usr/local|${PREFIX}|' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%RC_SUBR%%|${RC_SUBR}|' \
		${FILESDIR}/sapserver.sh >${WRKDIR}/sapserver.sh
	@${CP} -f ${WRKSRC}/sap.cfg ${WRKSRC}/sap.cfg-dist
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|${PORTDOCS}||' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/sapserver.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
