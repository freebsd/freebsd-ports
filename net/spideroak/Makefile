# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spideroak
PORTVERSION=	5.0.3
#PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	https://spideroak.com/getbuild?platform=slackware&arch=i386&dummy=/
DISTNAME=	${PORTNAME}-${PORTVERSION}-i686-1

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
OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	MANPAGES

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,} \
		BINMODE=${BINMODE}

REINPLACE_ARGS=	-e 's,%%PREFIX%%,${PREFIX},1' \
		-e 's,%%DATADIR%%,${DATADIR},1' \
		-i.bak

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USE_PYTHON=	2.7
USES=	desktop-file-utils

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} ${WRKDIR}/usr/share/applications/SpiderOak.desktop \
		${WRKDIR}/usr/bin/SpiderOak

# waiting to find a proper value for ${MTREE_LINUX_ARGS}...
stage-dir:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	@${MTREE_CMD} ${MTREE_ARGS} ${STAGEDIR}${PREFIX} > /dev/null

do-install:
	@(cd ${WRKDIR}/etc && \
	${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKDIR}/opt/SpiderOak/lib && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/usr/bin/SpiderOak ${STAGEDIR}${PREFIX}/bin/SpiderOak
	${LN} -sf SpiderOak ${STAGEDIR}${PREFIX}/bin/spideroak
	${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${STAGEDIR}${DESKTOPDIR} \
		${WRKDIR}/usr/share/applications/SpiderOak.desktop
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/usr/share/doc/SpiderOak/globalsync-linux.pdf ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MMANPAGES}
	${INSTALL_MAN} ${WRKDIR}/usr/share/man/man1/SpiderOak.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/
.endif
	${INSTALL_DATA} ${WRKDIR}/usr/share/pixmaps/*.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
