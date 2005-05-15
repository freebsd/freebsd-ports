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

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pipe||; s|-fmerge-constants||; s|-fno-unit-at-a-time||; s|--fast-math||' \
		 ${WRKSRC}/Makefile

.include <bsd.port.mk>
