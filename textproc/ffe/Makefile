# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffe
PORTVERSION=	0.3.5
CATEGORIES=	textproc
MASTER_SITES=	SF/ff-extractor/ff-extractor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flat file extractor

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo
GNU_CONFIGURE=	yes

INFO=		ffe
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	${PORTNAME}.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|setmode |setmode123 |' ${WRKSRC}/configure

.include <bsd.port.mk>
