# New ports collection makefile for:	wb0
# Date created:				2001-01-31
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	wb0
PORTVERSION=	000324
PORTREVISION=	1
CATEGORIES=	www graphics
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/clock/wb0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Web browser for svgalib which can show pictures

BROKEN=		incorrect packing list
RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx-current
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		vga.1:${PORTSDIR}/graphics/svgalib \
		png.5:${PORTSDIR}/graphics/png

DOCDIR=		share/doc/${PORTNAME}
DOCS=		AUTHORS Changelog README
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/pkg-plist

post-patch:
	@${MV} ${WRKSRC}/wb0.c ${WRKSRC}/wb0.c.orig
	@${SED} -e 's|/etc/wb0|${LOCALBASE}/etc|g ; \
		s|/usr/local/src/wb0/font/bit|${LOCALBASE}/share/wb0/|g' \
		< ${WRKSRC}/wb0.c.orig > ${WRKSRC}/wb0.c

pre-install:
	${ECHO_CMD} bin/wb0 > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} ${DOCDIR}/wb0.config.README >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif
	${ECHO_CMD} etc/wb0.config >> ${PLIST}
	for i in `${FIND} ${PREFIX}/share/wb0 -type f`; \
		do ${ECHO_CMD} share/wb0/`${BASENAME} $${i}` >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm share/wb0 >> ${PLIST}

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
