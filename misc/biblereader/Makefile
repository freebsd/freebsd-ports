# New ports collection makefile for:	biblereader
# Date created:        16 April 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	biblereader
PORTVERSION=	0.4.2
CATEGORIES=	misc
MASTER_SITES=	http://runnhide.cjb.net/sword/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI based Bible program for X11

USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

OPTIONS=	TRANSLATIONS	"Install translations"	on \
		COMMENTARIES	"Install commentaries"	on \
		DICTIONARIES	"Install dictionaries"	on

PLIST=		${WRKDIR}/PLIST
# Can be set to asv, kjv or web
DEFAULT_TRANSLATION?=	web

.include <bsd.port.pre.mk>

.if defined(WITH_TRANSLATIONS)
DISTFILES+=	asv-0.4${EXTRACT_SUFX} kjv-0.4.1${EXTRACT_SUFX} \
		web-0.4${EXTRACT_SUFX}
DATAFILES+=	${WRKDIR}/asv-0.4/asv ${WRKDIR}/kjv-0.4.1/kjv \
		${WRKDIR}/web-0.4/web
PLISTS+=	${PKGDIR}/pkg-plist.translations
.endif
.if defined(WITH_COMMENTARIES)
DISTFILES+=	mhc${EXTRACT_SUFX} wesley${EXTRACT_SUFX}
PLISTS+=	${PKGDIR}/pkg-plist.commentaries
DATAFILES+=	${WRKDIR}/mhc/mhc ${WRKDIR}/wesley/wesley
.endif
.if defined(WITH_DICTIONARIES)
DISTFILES+=	easton${EXTRACT_SUFX} strongs-0.4${EXTRACT_SUFX} \
		torrey${EXTRACT_SUFX}
PLISTS+=	${PKGDIR}/pkg-plist.dictionaries
DATAFILES+=	${WRKDIR}/easton/eastons.dict ${WRKDIR}/torrey/torrey.dict \
		${WRKDIR}/strongs-0.4/kjv-strongs \
		${WRKDIR}/strongs-0.4/strongs-greek.dict \
		${WRKDIR}/strongs-0.4/strongs-hebrew.dict
.endif
PLISTS+=	${PKGDIR}/pkg-plist

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" \
		-e "s:%%TRANSLATION%%:${DEFAULT_TRANSLATION}:" \
		${WRKSRC}/Makefile

pre-install:
	@${CAT} ${PLISTS} > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biblereader ${PREFIX}/bin/biblereader
	${MKDIR} ${DATADIR}
	for F in ${DATAFILES}; do \
		${INSTALL_DATA} $${F} ${DATADIR}; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
