# Created by: Marc Bruenink
# $FreeBSD$

PORTNAME=	coccinella
PORTVERSION=	0.96.20
PORTREVISION=	1
CATEGORIES=	net-im tk
MASTER_SITES=	SF
DISTNAME=	Coccinella-${PORTVERSION}Src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber client with whiteboard communication

LICENSE=	GPLv3

RUN_DEPENDS=	snack>=0:${PORTSDIR}/audio/snack \
		tcltls>=0:${PORTSDIR}/devel/tcltls \
		tkpng>=0:${PORTSDIR}/graphics/tkpng \
		tktray>=0:${PORTSDIR}/x11-toolkits/tktray \
		tktreectrl>=0:${PORTSDIR}/x11-toolkits/tktreectrl

NO_BUILD=	yes
USES=		tk

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS.txt CHANGES.txt README.txt

DOCSRCDIR2=	${WRKSRC}/READMEs
DOCSDIR2=	${DOCSDIR}/READMEs
DOC_FILES2=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

DESKTOP_ENTRIES="Coccinella" "" "${PORTNAME}" \
		"${PORTNAME}" "Network;InstantMessaging;" ""

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '1s|/usr/bin/env wish|${WISH}|' \
		${WRKSRC}/Coccinella.tcl
	@${REINPLACE_CMD} -e 's|exec tclsh|exec ${TCLSH}|' \
		${WRKSRC}/po/compile.tcl

do-install:
.for dir in TclXML certificates components contrib docs httpd iconsets items \
	jabber jabberlib lib plugins resources themes whiteboard xmpp
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/Coccinella.tcl ${STAGEDIR}${DATADIR}
	@${LN} -sf ${DATADIR}/Coccinella.tcl ${STAGEDIR}${PREFIX}/bin/coccinella

	${LN} -sf ${DATADIR}/themes/Oxygen/icons/64x64/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/po && ${CHMOD} 755 compile.tcl && \
		./compile.tcl)
	@(cd ${WRKSRC}/msgs && ${COPYTREE_SHARE} "*.msg" ${STAGEDIR}${DATADIR}/msgs)
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
