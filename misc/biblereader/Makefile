# New ports collection makefile for:	biblereader
# Date created:        16 April 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	biblereader
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} kjv.tar.gz
.if defined(WITH_TRANSLATIONS)
DISTFILES+=	asv.tar.gz darby.tar.gz
.endif
.if defined(WITH_NOTES)
DISTFILES+=	mhc.tar.gz
.endif
.if defined(WITH_DICTIONARIES)
DISTFILES+=	easton.tar.gz strongs.tar.gz torrey.tar.gz
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI based Bible program for X11

BROKEN=		unfetchable
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
PLIST=		${WRKDIR}/PLIST

DATAFILES=	${WRKDIR}/kjv/kjv
.if defined(WITH_TRANSLATIONS)
PLISTS+=	${PKGDIR}/pkg-plist.translations
DATAFILES+=	${WRKDIR}/asv/asv ${WRKDIR}/darby/darby
.endif
.if defined(WITH_NOTES)
PLISTS+=	${PKGDIR}/pkg-plist.notes
DATAFILES+=	${WRKDIR}/mhc/mhc
.endif
.if defined(WITH_DICTIONARIES)
PLISTS+=	${PKGDIR}/pkg-plist.dictionaries
DATAFILES+=	${WRKDIR}/easton/eastons.dict ${WRKDIR}/torrey/torrey.dict
DATAFILES+=	${WRKDIR}/strongs/kjv-strongs ${WRKDIR}/strongs/strongs-greek.dict ${WRKDIR}/strongs/strongs-hebrew.dict
.endif
PLISTS+=	${PKGDIR}/pkg-plist

pre-fetch:
.if !defined(WITH_TRANSLATIONS)
	@${ECHO_MSG}
	@${ECHO_MSG} "To download/install additional translations use"
	@${ECHO_MSG} "\"make install -DWITH_TRANSLATIONS\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_NOTES)
	@${ECHO_MSG}
	@${ECHO_MSG} "To download/install commentary and notes use"
	@${ECHO_MSG} "\"make install -DWITH_NOTES\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_DICTIONARIES)
	@${ECHO_MSG}
	@${ECHO_MSG} "To download/install dictionaries and notes use"
	@${ECHO_MSG} "\"make install -DWITH_DICTONARIES\""
	@${ECHO_MSG}
.endif

pre-install:
	@${CAT} ${PLISTS} > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biblereader ${PREFIX}/bin/biblereader
	${MKDIR} ${DATADIR}
	for F in ${DATAFILES}; do \
		${INSTALL_DATA} $${F} ${DATADIR}; \
	done

.include <bsd.port.mk>
