# New ports collection makefile for:	mulberry
# Date created:				12 Dec 2001
# Whom:					Yarema <yds@CoolRat.org>
#
# $FreeBSD$
#

PORTNAME=	mulberry
PORTVERSION=	2.1.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cyrusoft.com/pub/Mulberry/v${PORTVERSION:S/./_/g}/
DIST_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-rh6
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTCRYPTO=	MulberryS${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	yds@CoolRat.org

USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if defined(WITH_CRYPTO)
NO_CDROM=	Contains cryptography (can't redistribute)
NO_PACKAGE=	Contains cryptography (can't place on server for distribution)
RESTRICTED=	Contains cryptography (can't place on server for distribution)
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTCRYPTO})
IGNORE=	You must manually fetch the ${DISTCRYPTO} Plug-ins tarball from https://www.cyrusoft.com/cgi-bin/crypto and place it in ${DISTDIR}/${DIST_SUBDIR}/ and then run 'make -DWITH_CRYPTO install' again
.endif
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
DISTFILES+=	${DISTCRYPTO}
PLIST_SUB+=	CRYPTO=""
.else
PLIST_SUB+=	CRYPTO="@comment "
.endif

PLUGINSDIR=	${PREFIX}/lib/${PORTNAME}/Plug-ins
PIXMAPSDIR=	${PREFIX}/share/pixmaps

do-install:
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 0755 ${PLUGINSDIR}
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 0755 ${PIXMAPSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/Plug-ins/* ${PLUGINSDIR}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/icons/* ${PIXMAPSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}/CHANGES* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Mulberry_License ${DOCSDIR}
.endif

post-install:
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ""

.include <bsd.port.post.mk>
