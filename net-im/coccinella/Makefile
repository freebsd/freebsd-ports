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
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	snack>=0:audio/snack \
		tcltls>=0:devel/tcltls \
		tkpng>=0:graphics/tkpng \
		tktray>=0:x11-toolkits/tktray \
		tktreectrl>=0:x11-toolkits/tktreectrl

USES=		tk
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

DESKTOP_ENTRIES="Coccinella" "" "${PORTNAME}" \
		"${PORTNAME}" "Network;InstantMessaging;" ""

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

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
	${LN} -sf ${DATADIR}/Coccinella.tcl ${STAGEDIR}${PREFIX}/bin/coccinella
	${LN} -sf ${DATADIR}/themes/Oxygen/icons/64x64/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-NLS-on:
	@(cd ${WRKSRC}/po && ${CHMOD} 755 compile.tcl && \
		./compile.tcl)
	@(cd ${WRKSRC}/msgs && ${COPYTREE_SHARE} "*.msg" ${STAGEDIR}${DATADIR}/msgs)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS.txt CHANGES.txt README.txt READMEs" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
