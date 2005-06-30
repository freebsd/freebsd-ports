# New ports collection makefile for:	mulberry
# Date created:				12 Dec 2001
# Whom:					Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	mulberry
PORTVERSION=	3.1.6
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cyrusoft.com/pub/Mulberry/v${PORTVERSION:S/./_/g}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-rh6
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A scalable high-performance GUI internet Mail User Agent

NO_WRKSUBDIR=	yes
USE_LINUX=	yes
USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if defined(WITH_CRYPTO)
DISTCRYPTO=	${PORTNAME}-s-${PORTVERSION:S/./_/g}-rh6${EXTRACT_SUFX}
NO_CDROM=	Contains cryptography (cannot redistribute)
NO_PACKAGE=	Contains cryptography (cannot place on server for distribution)
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTCRYPTO})
IGNORE=	You must manually fetch the Linux RedHat 6.x ${DISTCRYPTO} Plug-ins tarball from https://www.cyrusoft.com/cgi-bin/crypto and place it in ${DISTDIR}/${DIST_SUBDIR}/ and then run 'make -DWITH_CRYPTO install' again
.endif
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
DISTFILES+=	${DISTCRYPTO}
PLIST_SUB+=	CRYPTO=""
.else
PLIST_SUB+=	CRYPTO="@comment "
.endif

INSTALL_DIR?=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755
PLUGINSDIR=	${PREFIX}/lib/${PORTNAME}/Plug-ins
PIXMAPSDIR=	${PREFIX}/share/pixmaps

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_DIR} ${PLUGINSDIR}
	${INSTALL_DIR} ${PIXMAPSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/Plug-ins/* ${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/icons/* ${PIXMAPSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/CHANGES* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Mulberry_License ${DOCSDIR}
.endif

post-install:
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ""

.include <bsd.port.post.mk>
