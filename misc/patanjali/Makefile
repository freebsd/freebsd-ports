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

MAINTAINER=	trevor@FreeBSD.org

PLIST=		${WRKDIR}/pkg-plist

do-patch:
	@${PERL} -pi -e 's:internet:Internet:g' \
		${WRKSRC}/patanjali-sutras-english.txt

pre-build:
	${RM} -f ${WRKSRC}/patanjali

do-build:
	${CC} -DDPPATHNAME=\"${DATADIR}/patanjali-sutras-english.txt\" \
		-DVERSION=\"1.0\" ${WRKSRC}/patanjali.c -o ${WRKSRC}/patanjali

pre-install:
	${ECHO} bin/patanjali > ${PLIST}
	${ECHO} share/patanjali/patanjali-sutras-english.txt >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/patanjali-sutras-english.txt ${DATADIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/patanjali ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/display-sutras-patanjali-0.99.lsm ${DOCSDIR}/
.endif

.include <bsd.port.mk>
