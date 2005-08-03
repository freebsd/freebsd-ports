# New ports collection makefile for:	lamprop
# Date created:				15 May 2005
# Whom:					rsmith@xs4all.nl
#
# $FreeBSD$
#

PORTNAME=	lamprop
PORTVERSION=	1.3.1
CATEGORIES=	science
MASTER_SITES=	http://www.xs4all.nl/~rsmith/software/

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Calculates properties of fiber reinforced composites

USE_REINPLACE=	yes

PLIST_FILES=	bin/lamprop

MAN1=		lamprop.1
MAN5=		lamprop.5
MANCOMPRESSED=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS=yes
.else
PORTDOCS=	LICENSE README NEWS
.endif

.include <bsd.port.pre.mk>

REP=	's|-pipe||; s|-fmerge-constants||; s|--fast-math||'
.if ${OSVERSION} < 500000
REP2+=	's|-fno-unit-at-a-time||;'
.endif

post-patch:
	@${REINPLACE_CMD} -e ${REP} ${WRKSRC}/Makefile
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e ${REP2} ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
