# New ports collection makefile for:    cyberbit-ttf
# Date created:                         20 Feb 2005
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cyberbit-ttfonts
PORTVERSION=	2.0.20050220
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.riken.go.jp/pub/net/netscape/communicator/extras/fonts/windows/ \
		ftp://ftp-au.netscape.com/pub/communicator/extras/fonts/windows/ \
		ftp://ftp.netscape.com/pub/communicator/extras/fonts/windows/
DISTFILES=	Cyberbit.ZIP
.if !defined(NOPORTDOCS)
DISTFILES+=	97CyberBase.Doc 97CyberBit.Doc 97CyberCJK.Doc \
		CYBERBIT.DOC CYBERCJK.DOC READMEfirst.txt ReadMe.htm
.endif
DIST_SUBDIR=	cyberbit
EXTRACT_ONLY=	Cyberbit.ZIP

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Bitstream Cyberbit is a TrueType font covers Unicode 2.0

RESTRICTED=	"Redistribution not permitted; single user license only."

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}
WRKSRC=		${WRKDIR}

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'xtt' module in /etc/x11/xorg.conf."
	@${ECHO} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/*.ttf \
			${FILESDIR}/fonts.alias.cyberbit \
			${FILESDIR}/fonts.dir.cyberbit \
			${PREFIX}/${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/97CyberBase.Doc ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/97CyberBit.Doc  ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/97CyberCJK.Doc  ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/CYBERBIT.DOC    ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/CYBERCJK.DOC    ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/READMEfirst.txt ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ReadMe.htm      ${DOCSDIR}
.endif
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.include <bsd.port.mk>
