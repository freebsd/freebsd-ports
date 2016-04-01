# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	w_scan
PORTVERSION=	20120415
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/w_scan/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=  v4l_compat>=1.0.20120501:multimedia/v4l_compat

PATCH_STRIP=	-lp1

GNU_CONFIGURE=	yes
USES=		gettext iconv localbase tar:bzip2
LDFLAGS+=	${ICONV_LIB}
NO_WRKSUBDIR=	yes

PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	LINUX DOCS

LINUX_DESC=		Install Linux binary too (linux-w_scan)
LINUX_USE=		LINUX=yes
LINUX_RUN_DEPENDS=	linux_dvbwrapper-kmod>=1.0:multimedia/linux_dvbwrapper-kmod
LINUX_PLIST_FILES=	bin/linux-${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/configure ${WRKSRC}/*.c ${WRKSRC}/*.h
	@${CP} ${WRKSRC}/${PORTNAME} ${WRKSRC}/linux-${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-LINUX-on:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} linux-${PORTNAME} ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
