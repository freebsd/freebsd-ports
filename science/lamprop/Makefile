# Created by: rsmith@xs4all.nl
# $FreeBSD$

PORTNAME=	lamprop
PORTVERSION=	1.3.3
CATEGORIES=	science
MASTER_SITES=	http://rsmith.home.xs4all.nl/software/

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Calculates properties of fiber reinforced composites

PLIST_FILES=	bin/lamprop

MAN1=		lamprop.1
MAN5=		lamprop.5
MANCOMPRESSED=	yes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

.if defined(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS=yes
.else
PORTDOCS=	LICENSE README NEWS
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|-pipe||; s|-fmerge-constants||; s|-fno-unit-at-a-time||; s|--fast-math||' \
		 ${WRKSRC}/Makefile

.include <bsd.port.mk>
