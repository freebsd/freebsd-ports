# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$


PORTNAME=	wmpop3
PORTVERSION=	0.5.6a
PORTREVISION=	4
CATEGORIES=	mail windowmaker
MASTER_SITES=	#
DISTNAME=	WMPop3-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 mail check for the Window Maker dock

WRKSRC=		${WRKDIR}/${DISTNAME:L}/wmpop3

USE_CSTD=	gnu89
USE_XORG=	xpm
ALL_TARGET=	clean all
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/wmpop3 %%EXAMPLESDIR%%/wmpop3rc
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpop3 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wmpop3rc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
