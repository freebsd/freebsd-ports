# New ports collection makefile for:	mulberry
# Date created:				12 Dec 2001
# Whom:					Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	mulberry
PORTVERSION=	4.0.8
CATEGORIES=	mail
MASTER_SITES=	http://www.mulberrymail.com/downloads/Mulberry/%SUBDIR%/
MASTER_SITE_SUBDIR=v${PORTVERSION:S/./_/g}
DISTNAME=	Mulberry
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A scalable high-performance GUI internet Mail User Agent

NO_WRKSUBDIR=	yes
USE_LINUX=	yes
USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
PLUGINSDIR=	${PREFIX}/lib/${PORTNAME}/Plug-ins
RESOURCESDIR=	${PREFIX}/lib/${PORTNAME}/Resources
PIXMAPSDIR=	${PREFIX}/share/pixmaps

SUB_LIST=	PORTNAME=${PORTNAME} WRKSRC=${WRKSRC}
PLIST_SUB=	PORTNAME=${PORTNAME}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_DIR} ${PLUGINSDIR}
	${INSTALL_DIR} ${PIXMAPSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
#	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/lib/${PORTNAME}/${PORTNAME}.bin
#	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/Plug-ins/*.so ${PLUGINSDIR}
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/Resources
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/Resources/* ${RESOURCESDIR}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/icons/* ${PIXMAPSDIR}
	${INSTALL_DIR} ${PLUGINSDIR}/Timezones
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/Plug-ins/Timezones/* ${PLUGINSDIR}/Timezones
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mailcap ${EXAMPLESDIR}
	@[ -f ${PREFIX}/etc/mailcap ] || ${INSTALL_DATA} ${FILESDIR}/mailcap ${PREFIX}/etc/mailcap
	${INSTALL_DATA} ${FILESDIR}/url.helpers ${EXAMPLESDIR}
	@[ -f ${PREFIX}/lib/url.helpers ] || ${INSTALL_DATA} ${FILESDIR}/url.helpers ${PREFIX}/lib/url.helpers
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/CHANGES* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Mulberry_License ${DOCSDIR}
.endif
.include <bsd.port.post.mk>
