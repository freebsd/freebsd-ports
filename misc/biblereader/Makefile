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

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG=${GTK_CONFIG}
PLIST=      ${WRKDIR}/PLIST

DATAFILES= ${WRKDIR}/kjv/kjv
.if defined(WITH_TRANSLATIONS)
DATAFILES+= ${WRKDIR}/asv/asv ${WRKDIR}/darby/darby
PLISTS+= ${PKGDIR}/PLIST.translations
.endif
.if defined(WITH_SUPPLEMENTS)
DATAFILES+= ${WRKDIR}/easton/easton.dict ${WRKDIR}/mhc/mhc
PLISTS+= ${PKGDIR}/PLIST.supplements
.endif

PLISTS+=    ${PKGDIR}/PLIST

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

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
	@echo ${DATAFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/biblereader ${PREFIX}/bin/biblereader
	${MKDIR} ${PREFIX}/share/biblereader
	@for file in ${DATAFILES}; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/biblereader; \
	done
	@cat ${PLISTS} > ${PLIST}

.include <bsd.port.mk>
