# New ports collection makefile for:	faces-1.6.1
# Date created:		09 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
#			Andreas Klemm <andreas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	faces
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

# Define USE_NAS for NAS audio support
.if defined(USE_NAS)
RUN_DEPENDS=	auplay:${PORTSDIR}/audio/nas
SED_REPL=auplay
.else
RUN_DEPENDS=	rplay:${PORTSDIR}/audio/rplay
SED_REPL=rplay
.endif

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/faces
MAN1=		compface.1 faces.1 face_update.1
MAN3=		compface.3
MLINKS=		compface.1 uncompface.1 \
		compface.3 uncompface.3

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

post-patch:
	for na in $$(find ${WRKSRC}/scripts -type f) \
		${WRKSRC}/faces.man ${WRKSRC}/face_update.1 ; do \
	    ${CP} $$na $$na.orig; \
	    ${SED} "s%/usr/local%${PREFIX}%" $$na.orig > $$na; \
	done; \
	for na in ${WRKSRC}/Makefile ${WRKSRC}/Faces.ad; do \
	    ${CP} $$na $$na.orig; \
	    ${SED} "s%rplay%${SED_REPL}%" $$na.orig > $$na; \
	done; \
	for na in ${WRKSRC}/Makefile ${WRKSRC}/x11.c; do \
	    ${CP} $$na $$na.orig2; \
	    ${SED} "s%/usr/X11R6%${X11BASE}%" $$na.orig2 > $$na; \
	done

.if !defined(NOPORTDOCS)
post-install:
	if [ ! -e ${PREFIX}/share/doc/${PORTNAME} ]; then \
	    ${MKDIR} ${PREFIX}/share/doc/${PORTNAME}; \
	    ${CP} -f ${WRKSRC}/README                 ${PREFIX}/share/doc/${PORTNAME}; \
	    ${CP} -f ${WRKSRC}/scripts/README.kinzler ${PREFIX}/share/doc/${PORTNAME}; \
	    ${CP} -f ${WRKSRC}/scripts/from.allrc-eg  ${PREFIX}/share/doc/${PORTNAME}; \
	    ${MKDIR} ${PREFIX}/share/${PORTNAME}/lib; \
	    ${ECHO} ";# See ${PREFIX}/share/doc/${PORTNAME}/from.allrc-eg for an example" \
		> ${PREFIX}/share/${PORTNAME}/lib/allrc; \
	fi
.endif

.include <bsd.port.mk>
