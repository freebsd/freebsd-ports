# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-sleeptimer
PORTVERSION=	0.8.2
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/652/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - sleep timer plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}

NO_STAGE=	yes
.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
