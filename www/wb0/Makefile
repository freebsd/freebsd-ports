# New ports collection makefile for:	wb0
# Date created:				2001-01-31
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	wb0
PORTVERSION=	000324
CATEGORIES=	www graphics
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/clock/wb0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx-current
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		vga.1:${PORTSDIR}/graphics/svgalib \
		png.4:${PORTSDIR}/graphics/png

DOCDIR=		share/doc/${PORTNAME}
DOCS=		AUTHORS Changelog README
PLIST=		${WRKDIR}/pkg-plist

post-patch:
	${PERL} -pi -e 's|/etc/wb0|${LOCALBASE}/etc|g ; \
		s|/usr/local/src/wb0/font/bit|${LOCALBASE}/share/wb0/|g' \
		${WRKSRC}/wb0.c

pre-install:
	${ECHO} bin/wb0 > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO} ${DOCDIR}/wb0.config.README >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif
	${ECHO} etc/wb0.config >> ${PLIST}
	for i in `find ${PREFIX}/share/wb0 -type f`; \
		do ${ECHO} share/wb0/`${BASENAME} $${i}` >> ${PLIST}; \
	done
	${ECHO} @dirrm share/wb0 >> ${PLIST}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/wb0/wb0.config.README ${PREFIX}/${DOCDIR}
	${ECHO} ${DOCDIR}/
.endif

.include <bsd.port.mk>
