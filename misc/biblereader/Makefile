# New ports collection makefile for:	biblereader
# Date created:        16 April 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	biblereader
PORTVERSION=	0.3.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.whitevine.com/biblereader/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} kjv.tar.gz
.if defined(WITH_TRANSLATIONS)
DISTFILES+=	asv.tar.gz darby.tar.gz
.endif
.if defined(WITH_SUPPLEMENTS)
DISTFILES+=	easton.tar.gz mhc.tar.gz
.endif

MAINTAINER=	patseal@hyperhost.net

USE_X_PREFIX=	yes
USE_GTK=	yes
PLIST=		${WRKDIR}/PLIST

DATAFILES=	${WRKDIR}/kjv/kjv
PLISTS=		${PKGDIR}/pkg-plist
.if defined(WITH_TRANSLATIONS)
DATAFILES+= 	${WRKDIR}/asv/asv ${WRKDIR}/darby/darby
PLISTS+= 	${PKGDIR}/pkg-plist.translations
.endif
.if defined(WITH_SUPPLEMENTS)
DATAFILES+= 	${WRKDIR}/easton/easton.dict ${WRKDIR}/mhc/mhc
PLISTS+= 	${PKGDIR}/pkg-plist.supplements
.endif

.if !defined(WITH_TRANSLATIONS)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to download/install additional tranlations use"
	@${ECHO_MSG} "\"make -DWITH_TRANSLATIONS\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_SUPPLEMENTS)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want download/install commentary and dictionary files please use"
	@${ECHO_MSG} "\"make -DWITH_SUPPLEMENTS\""
	@${ECHO_MSG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biblereader ${PREFIX}/bin/biblereader
	${MKDIR} ${PREFIX}/share/biblereader
	@for file in ${DATAFILES}; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/biblereader; \
	done
	@${CAT} ${PLISTS} > ${PLIST}

.include <bsd.port.mk>
