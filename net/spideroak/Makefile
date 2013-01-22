# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spideroak
PORTVERSION=	4.8.3.10016
#PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://spideroak.com/getbuild?platform=slackware&arch=${ARCH:S,amd,x86_,}&dummy=/
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${ARCH:C,amd,x86_,}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	SpiderOak Client (Linux version)

LICENSE_NAME=	ToU
LICENSE_TEXT=	http://spideroak.com/terms_of_use
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FETCH_ARGS=	-Fpr

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binary distribution
OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,} \
		LINARCH=${LINARCH} \
		ONLYI386=${ONLYI386}

REINPLACE_ARGS=	-e 's,%%PREFIX%%,${PREFIX},1' \
		-e 's,%%DATADIR%%,${DATADIR},1' \
		-i.bak

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=	SpiderOak.1
MANCOMPRESSED=	yes
.endif

USE_GNOME=	desktopfileutils
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USE_PYTHON=	2.7

post-patch:
	${REINPLACE_CMD} ${WRKDIR}/usr/share/applications/SpiderOak.desktop \
		${WRKDIR}/usr/bin/SpiderOak

do-install:
	cd ${WRKDIR}/etc && \
	${COPYTREE_SHARE} . ${PREFIX}/etc/
	${MKDIR} ${DATADIR}
	cd ${WRKDIR}/opt/SpiderOak/lib && \
	${COPYTREE_SHARE} . ${DATADIR}
	${CHMOD} ${BINMODE} ${DATADIR}/SpiderOak ${DATADIR}/inotify_dir_watcher
	${INSTALL_SCRIPT} ${WRKDIR}/usr/bin/SpiderOak ${PREFIX}/bin/SpiderOak
	${LN} -s ${PREFIX}/bin/SpiderOak ${PREFIX}/bin/spideroak
	${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${DESKTOPDIR} \
		--rebuild-mime-info-cache \
		${WRKDIR}/usr/share/applications/SpiderOak.desktop
.if ${PORT_OPTIONS:MMANPAGES}
	${INSTALL_MAN} ${WRKDIR}/usr/share/man/man1/SpiderOak.1.gz ${MANPREFIX}/man/man1/
.endif
	${INSTALL_DATA} ${WRKDIR}/usr/share/pixmaps/SpiderOak.png ${PREFIX}/share/pixmaps/

post-install:
	-${LOCALBASE}/bin/update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
LINARCH=	"i686"
ONLYI386=	""
.else
LINARCH=	"x86_64"
ONLYI386=	"@comment "
.endif

.include <bsd.port.post.mk>
