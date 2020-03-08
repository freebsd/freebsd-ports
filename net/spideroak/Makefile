# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spideroak
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/${PORTNAME}/ \
		https://spideroak.com/getbuild?platform=slackware&arch=i386&dummy=/
DISTNAME=	SpiderOak-${PORTVERSION}-i686-1

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	SpiderOak Client (Linux version)

LICENSE=	TOU
LICENSE_NAME=	Terms Of Use
LICENSE_TEXT=	http://spideroak.com/terms_of_use
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binary distribution
OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,} \
		BINMODE=${BINMODE}

SUB_LIST=	LINUXBASE=${LINUXBASE}
SUB_FILES=	pkg-message

USES=		desktop-file-utils linux python:2.7 tar:tgz
USE_LINUX=	xorglibs

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},1' \
		-e 's,%%DATADIR%%,${DATADIR},1' \
		${WRKSRC}/usr/share/applications/SpiderOakONE.desktop \
		${WRKSRC}/usr/bin/SpiderOakONE

do-install:
	@(cd ${WRKSRC}/etc && \
	${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/opt/SpiderOakONE/lib && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "-not -name SpiderOak")
	${INSTALL_PROGRAM} ${WRKSRC}/opt/SpiderOakONE/lib/SpiderOakONE ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/SpiderOakONE ${STAGEDIR}${PREFIX}/bin/SpiderOakONE
	${LN} -sf SpiderOakONE ${STAGEDIR}${PREFIX}/bin/spideroak
	${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${STAGEDIR}${DESKTOPDIR} \
		${WRKSRC}/usr/share/applications/SpiderOakONE.desktop
	${INSTALL_DATA} ${WRKSRC}/usr/share/pixmaps/*.png ${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usr/share/doc/SpiderOakONE/Getting\ Started\ Guide.pdf ${STAGEDIR}${DOCSDIR}

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/SpiderOakONE.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
