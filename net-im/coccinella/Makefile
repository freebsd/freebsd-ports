# Created by: Marc Bruenink
# $FreeBSD$

PORTNAME=	coccinella
PORTVERSION=	0.96.20
CATEGORIES=	net-im tk
MASTER_SITES=	SF
DISTNAME=	Coccinella-${PORTVERSION}Src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber client with whiteboard communication

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	snack>=0:${PORTSDIR}/audio/snack \
		tcltls>=0:${PORTSDIR}/devel/tcltls \
		tkpng>=0:${PORTSDIR}/graphics/tkpng \
		tktray>=0:${PORTSDIR}/x11-toolkits/tktray \
		tktreectrl>=0:${PORTSDIR}/x11-toolkits/tktreectrl

NO_BUILD=	yes

USE_TK_WRAPPER=	yes

LIBTARGETDIR=	${PREFIX}/${PORTNAME}
PLIST_SUB=	LIBTARGETDIR="${PORTNAME}"

NO_STAGE=	yes
do-install:
	@${MKDIR} ${LIBTARGETDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Coccinella.tcl ${LIBTARGETDIR}
	@${LN} -sf ${LIBTARGETDIR}/Coccinella.tcl ${PREFIX}/bin/coccinella
.for dir in TclXML certificates components contrib docs httpd iconsets items \
	jabber jabberlib lib msgs plugins po resources themes whiteboard xmpp
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${LIBTARGETDIR})
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS.txt CHANGES.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} READMEs ${DOCSDIR})
.endif

.include <bsd.port.mk>
