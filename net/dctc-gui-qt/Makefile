# New ports collection makefile for:	dctc qt gui
# Date created:		Sun Jul 28 7:00:43 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dc-qt
PKGNAMESUFFIX=	-gui-qt
DISTNAME=	dc-qt-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A Qt GUI for the Direct Connect (TM) dctc text client

RUN_DEPENDS=	dctc:${PORTSDIR}/net/dctc

USE_QT_VER=	3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
PLIST_FILES=	bin/dc_qt

OPTIONS=	XINE "Enable support for video preview using libxine" off

XINE_CONFIG?=	${X11BASE}/bin/xine-config

.ifndef(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	\
		about.html \
		advanced.html \
		basic.html \
		config.html \
		connect.html \
		index.html \
		logo.png \
		mainwindow.png \
		searchdl.html
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

# with xine preview support
.ifdef(WITH_XINE)
LIB_DEPENDS+=		xine:${PORTSDIR}/multimedia/libxine
CONFIGURE_ENV+=		XINE_CONFIG=${XINE_CONFIG}
.else
CONFIGURE_ARGS+=	--disable-preview
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|(HUBLIST[[:space:]]*=[[:space:]]*")hublist"|\1dc_hublist"|' \
		${WRKSRC}/src/dc_hub.cc
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's|^(SUBDIRS).+$$|\1=|' \
		${WRKSRC}/src/Makefile.in
.else
	@${REINPLACE_CMD} -E \
		-e 's|^(pkgdatadir).+$$|\1=${DOCSDIR}|' \
		${WRKSRC}/src/doc/Makefile.in
.endif

post-configure:
# uphold CC/CXX/CFLAGS
	@${REINPLACE_CMD} -E \
		-e 's|^(CXXFLAGS.+)$$|\1 ${CXXFLAGS}|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/src/Makefile

.include <bsd.port.post.mk>
