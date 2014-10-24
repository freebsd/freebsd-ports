# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spideroak
PORTVERSION=	5.1.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/${PORTNAME}/ \
		https://spideroak.com/getbuild?platform=slackware&arch=i386&dummy=/
DISTNAME=	${PORTNAME}-${PORTVERSION}-i686-1

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	SpiderOak Client (Linux version)

LICENSE=	TOU
LICENSE_NAME=	Terms Of Use
LICENSE_TEXT=	http://spideroak.com/terms_of_use
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binary distribution
OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,} \
		BINMODE=${BINMODE}

REINPLACE_ARGS=	-e 's,%%PREFIX%%,${PREFIX},1' \
		-e 's,%%DATADIR%%,${DATADIR},1' \
		-i.bak

SUB_LIST=	LINUXBASE=${LINUXBASE}
SUB_FILES=	pkg-message

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USES=		desktop-file-utils python:2

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} ${WRKDIR}/usr/share/applications/SpiderOak.desktop \
		${WRKDIR}/usr/bin/SpiderOak

do-install:
	@(cd ${WRKDIR}/etc && \
	${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKDIR}/opt/SpiderOak/lib && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-not -name SpiderOak")
	${INSTALL_PROGRAM} ${WRKDIR}/opt/SpiderOak/lib/SpiderOak ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/usr/bin/SpiderOak ${STAGEDIR}${PREFIX}/bin/SpiderOak
	${LN} -sf SpiderOak ${STAGEDIR}${PREFIX}/bin/spideroak
	${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${STAGEDIR}${DESKTOPDIR} \
		${WRKDIR}/usr/share/applications/SpiderOak.desktop
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/usr/share/doc/SpiderOak/globalsync-linux.pdf ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MMANPAGES}
	${INSTALL_MAN} ${WRKDIR}/usr/share/man/man1/SpiderOak.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
.endif
	${INSTALL_DATA} ${WRKDIR}/usr/share/pixmaps/*.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
