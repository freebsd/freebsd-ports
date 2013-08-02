# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmpop3
PORTVERSION=	0.5.6a
PORTREVISION=	4
CATEGORIES=	mail windowmaker
MASTER_SITES=	#
DISTNAME=	WMPop3-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp to check email via POP3 protocol

LICENSE=	GPLv2

USE_CSTD=	gnu89
USE_XORG=	xpm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

PLIST_FILES=	bin/wmpop3
PORTDOCS=	CHANGE_LOG README
PORTEXAMPLES=	wmpop3rc

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpop3 ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wmpop3rc ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
