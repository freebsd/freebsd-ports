# New ports collection makefile for:	patanjali
# Date created:				2002-01-09
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	patanjali
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.linuxlabs.com/software/download/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a verse from Yoga Sutras of Patanjali

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	share/patanjali
SUTRAS=		patanjali-sutras-english.txt

do-patch:
	@${MV} ${WRKSRC}/${SUTRAS} ${WRKSRC}/${SUTRAS}.orig
	@${SED} -e 's:internet:Internet:g' \
		< ${WRKSRC}/${SUTRAS}.orig > ${WRKSRC}/${SUTRAS}

pre-build:
	${RM} -f ${WRKSRC}/patanjali

do-build:
	${CC} -DDPPATHNAME=\"${DATADIR}/${SUTRAS}\" \
		-DVERSION=\"1.0\" ${WRKSRC}/patanjali.c -o ${WRKSRC}/patanjali

pre-install:
	${ECHO_CMD} bin/patanjali > ${PLIST}
	${ECHO_CMD} share/patanjali/${SUTRAS} >> ${PLIST}
.if !defined(NOPORTDOCS)
	${ECHO_CMD} share/doc/patanjali/display-sutras-patanjali-0.99.lsm >> ${PLIST}
	${ECHO_CMD} @dirrm share/doc/patanjali/ >> ${PLIST}
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${SUTRAS} ${DATADIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/patanjali ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/display-sutras-patanjali-0.99.lsm ${DOCSDIR}/
.endif

.include <bsd.port.mk>
