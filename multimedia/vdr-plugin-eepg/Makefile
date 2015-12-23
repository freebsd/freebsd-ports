# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-eepg
PORTVERSION=	0.0.6p2011071921
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/p.*/pre/}-0-g${GITHASH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - extended EPG plugin

GITHASH=	e7383ed
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PORTNAME}-${GITHASH}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}
	${INSTALL_DATA} ${WRKSRC}/eepg.equiv.IT ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}
	${INSTALL_DATA} ${WRKSRC}/eepg.equiv.IT ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/eepg.equiv.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
