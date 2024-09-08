PORTNAME=	linux-whatsdesk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.9
CATEGORIES=	net-im
MASTER_SITES=	https://zerkc.gitlab.io/whatsdesk/
DISTFILES=	whatsdesk_${DISTVERSION}_amd64.deb
EXTRACT_ONLY=	${DISTFILES:R}.tar.xz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Unofficial client of Whatsapp
WWW=		https://gitlab.com/zerkc/whatsdesk

LICENSE=	AGPLv3 BSD3CLAUSE CC-BY-2.5 CC-BY-3.0 LGPL21 MIT MPL11
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64

EXTRACT_DEPENDS=	deb2targz:archivers/deb2targz

USES=		desktop-file-utils linux:rl9 tar:xz
USE_LINUX=	alsa-plugins-oss alsa-plugins-pulseaudio alsalib at-spi2-atk \
		atk ca-certificates cups-libs dbuslibs devtools gtk3 libdrm \
		libsigsegv nss opus

NO_BUILD=	yes
SUB_FILES=	${PORTNAME}
SUB_LIST=	LINUXBASE=${LINUXBASE}

NO_WRKSUBDIR=	yes

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

pre-extract:
	${LOCALBASE}/bin/deb2targz ${DISTDIR}/${DISTFILES}

# remove artifact of deb2targz
post-extract:
	@${RM} ${DISTDIR}/${DISTFILES:R}.tar.xz

post-patch:
	${REINPLACE_CMD} -i "" \
		-e "s,/opt/whatsdesk/\(whatsdesk\),${PREFIX}/bin/linux-\1,1" \
		${WRKSRC}/usr/share/applications/whatsdesk.desktop

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/opt/whatsdesk && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} \
			"-not -regex \./LICENSE.*")
	(cd ${WRKSRC}/usr/share && \
		${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/share \
			"-not -regex \./doc.*")
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/bin/${PORTNAME}
	(cd ${STAGEDIR}${DATADIR} && \
		${STRIP_CMD} chrome-sandbox libvulkan.so.1)

.include <bsd.port.mk>
