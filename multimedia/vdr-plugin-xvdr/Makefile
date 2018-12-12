# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-xvdr
PORTVERSION=	0.9.5
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox/
DISTNAME=	pipelka-${PORTNAME}-xvdr-${PORTVERSION}-0-g${GITHASH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - XVDR server plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GITHASH=	e4cab47
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/pipelka-${PORTNAME}-${GITHASH}

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}
	${INSTALL_DATA} ${WRKSRC}/${PLUGIN}/allowed_hosts.conf \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
