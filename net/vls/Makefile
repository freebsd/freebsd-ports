# New ports collection makefile for:	vls
# Date created:		3rd August 2001
# Whom:			Gleb Smirnoff <glebius@cell.sick.ru>
#
# $FreeBSD$
#

PORTNAME=	vls
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	net multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vls/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An X11 video streaming client/server solution

LIB_DEPENDS=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
.if !defined(WITHOUT_DVD)
LIB_DEPENDS+=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CFLAGS+=	-I${LOCALBASE}/inlcude

CONFIGURE_ARGS+=	--with-dvbpsi=${LOCALBASE}
.if !defined(WITHOUT_DVD)
CONFIGURE_ARGS+=	--with-dvdcss=${LOCALBASE} \
			--with-dvdread=${LOCALBASE}
PLIST_SUB+=		WITHDVD=""
.else
CONFIGURE_ARGS+=	--disable-dvd
PLIST_SUB+=		WITHDVD="@comment "
.endif

pre-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/vls-guide.sgml ${DOCSDIR}/
	${CP} -pR ${WRKSRC}/doc/developer ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ENV+=		VLS_LIB="-L/usr/lib -lcipher"
.endif

.include <bsd.port.post.mk>
