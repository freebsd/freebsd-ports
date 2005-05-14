# New ports collection makefile for:	vls
# Date created:		3rd August 2001
# Whom:			Gleb Smirnoff <glebius@cell.sick.ru>
#
# $FreeBSD$
#

PORTNAME=	vls
PORTVERSION=	0.5.6
CATEGORIES=	net ipv6 multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vls/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Broadcasts MPEG(1/2/4, PS/TS) video streams

LIB_DEPENDS=	dvbpsi.3:${PORTSDIR}/multimedia/libdvbpsi
.if !defined(WITHOUT_DVD)
LIB_DEPENDS+=	dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CFLAGS+=	-I${LOCALBASE}/inlcude

CONFIGURE_ARGS+=	--with-dvbpsi=${LOCALBASE}
.if !defined(WITHOUT_DVD)
CONFIGURE_ARGS+=	--with-dvdcss=${LOCALBASE} \
			--with-dvdread=${LOCALBASE}
PLIST_FILES+=	lib/videolan/vls/dvdreader.so
.else
CONFIGURE_ARGS+=	--disable-dvd
.endif

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%RC_SUBR%%|${RC_SUBR}|g' \
		${FILESDIR}/vlsd.sh.in > ${WRKDIR}/vlsd.sh

pre-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/developer
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${CP} -pR ${WRKSRC}/doc/developer/*.* ${DOCSDIR}/developer/
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vlsd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ENV+=		VLS_LIB="-L/usr/lib -lcipher"
.endif

.if ${OSVERSION} >= 502122
# allow nonconforming code to compile
CFLAGS+=	-fpermissive
.endif

.include <bsd.port.post.mk>
