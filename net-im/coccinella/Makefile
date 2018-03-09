# Created by: Marc Bruenink
# $FreeBSD$

PORTNAME=	coccinella
PORTVERSION=	0.96.20
PORTREVISION=	2
CATEGORIES=	net-im tk
MASTER_SITES=	SF
DISTNAME=	Coccinella-${PORTVERSION}Src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber client with whiteboard communication

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	snack>=0:audio/snack \
		tcltls>=0:devel/tcltls \
		tkpng>=0:graphics/tkpng \
		tktray>=0:x11-toolkits/tktray \
		tktreectrl>=0:x11-toolkits/tktreectrl

USES=		shebangfix tk
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

SHEBANG_FILES=	Coccinella.tcl
SHEBANG_LANG=	wish
wish_CMD=	${WISH}

DESKTOP_ENTRIES="Coccinella" "" "${PORTNAME}" "${PORTNAME}" "Network;InstantMessaging;" ""

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's|exec tclsh|exec ${TCLSH}|' ${WRKSRC}/po/compile.tcl
	@${CHMOD} 755 ${WRKSRC}/po/compile.tcl

post-build-NLS-on:
	(cd ${WRKSRC}/po && ./compile.tcl)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_SCRIPT} ${WRKSRC}/Coccinella.tcl ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/Coccinella.tcl ${STAGEDIR}${PREFIX}/bin/coccinella
.for dir in TclXML certificates components contrib docs httpd iconsets items \
	jabber jabberlib lib plugins resources themes whiteboard xmpp
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor
	${RLN} ${STAGEDIR}${DATADIR}/themes/Oxygen/icons/64x64/coccinella.png ${STAGEDIR}${PREFIX}/share/pixmaps/coccinella.png

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/msgs
	${INSTALL_DATA} ${WRKSRC}/msgs/*.msg ${STAGEDIR}${DATADIR}/msgs

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS.txt CHANGES.txt README.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/READMEs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
