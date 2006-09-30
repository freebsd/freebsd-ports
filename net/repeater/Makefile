# New ports collection makefile for:	repeater
# Date created:				14 December 2005
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	repeater
PORTVERSION=	0.08
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://koti.mbnet.fi/jtko/uvncrepeater/
DISTNAME=	repeater${PORTVERSION:C/\.//}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	UltraVNC repeater

USE_ZIP=	yes
USE_RC_SUBR=	repeater
WRKSRC=		${WRKDIR}/Ver${PORTVERSION:C/\.//}
ALL_TARGET=	repeater

PLIST_FILES=	sbin/repeater

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repeater ${PREFIX}/sbin/repeater

.if !defined(NOPORTDOCS)
PORTDOCS=	changelog.txt readme.txt ultravncrepeaterlinuxport.html

post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
