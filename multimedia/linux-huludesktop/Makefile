# New ports collection makefile for:	multimedia/linux-huludesktop
# Date created:			2010-02-22
# Whom:				Joseph S. Atkinson <jsa@wickedmachine.net>
#
# $FreeBSD$
#

PORTNAME=	huludesktop
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	multimedia linux
MASTER_SITES=	http://download.hulu.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${LINUX_RPM_ARCH}
EXTRACT_SUFX=	.rpm

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Streaming video client for TV and movies on Hulu.com

ONLY_FOR_ARCHS=	i386 amd64
LINUX_RPM_ARCH=	i386

USE_LINUX=	f10
USE_LINUX_APPS=	gtk2
NO_BUILD=	yes

RPM2CPIO?=	${LOCALBASE}/bin/rpm2cpio
FLASHPLUGIN=	linux-${USE_LINUX}-flashplugin
FLASHPATH=	${LOCALBASE}/lib/npapi/${FLASHPLUGIN}/libflashplayer.so
EXTRACT_DEPENDS+=	${RPM2CPIO}:${PORTSDIR}/archivers/rpm
RUN_DEPENDS+=	${FLASHPATH}:${PORTSDIR}/www/${FLASHPLUGIN}10

RESTRICTED=	Non-redistributable, non-commercial, export controlled

SUB_FILES=	${PORTNAME}

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKSRC}
	${RPM2CPIO} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} xf - -C ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME} \
		${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/${PORTNAME} \
		${PREFIX}/libexec/${PORTNAME}.bin
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}/hd_keymap.ini \
		${PREFIX}/etc/${PORTNAME}
.	for FILE in applications/${PORTNAME}.desktop pixmaps/${PORTNAME}.png
		${INSTALL_DATA} ${WRKSRC}/usr/share/${FILE} \
			${PREFIX}/share/${FILE}
.	endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for FILE in EULA LICENSE README
		${INSTALL_DATA} ${WRKSRC}/usr/share/doc/${PORTNAME}/${FILE} \
			${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
