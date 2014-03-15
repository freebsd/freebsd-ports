# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w_scan
PORTVERSION=	20120415
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/w_scan/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions

BUILD_DEPENDS=  v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat

OPTIONS_DEFINE=	LINUX
LINUX_DESC=	Install Linux binary too (linux-w_scan)

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
PATCH_STRIP=	-lp1
USES+=		gettext iconv tar:bzip2
CPPFLAGS+=	-I"${LOCALBASE}/include"
LDFLAGS+=	-L"${LOCALBASE}/lib\ ${ICONV_LIB}"
PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/${PORTNAME}
PLIST_FILES+=	man/man1/${PORTNAME}.1.gz
WRKSRC=		${WRKDIR}

.if ${PORT_OPTIONS:MLINUX}
USE_LINUX=	yes
RUN_DEPENDS+=	linux_dvbwrapper-kmod>=1.0:${PORTSDIR}/multimedia/linux_dvbwrapper-kmod
PLIST_FILES+=	bin/linux-${PORTNAME}
.endif

post-patch:
	${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/configure ${WRKSRC}/*.c ${WRKSRC}/*.h
	${CP} ${WRKSRC}/${PORTNAME} ${WRKSRC}/linux-${PORTNAME}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MLINUX}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} linux-${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
.endif

.include <bsd.port.mk>
