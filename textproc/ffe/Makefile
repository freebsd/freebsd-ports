# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffe
PORTVERSION=	0.3.6
CATEGORIES=	textproc
MASTER_SITES=	SF/ff-extractor/ff-extractor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flat file extractor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_setmode=no # looks for wrong kind of setmode()

INFO=		ffe
PORTDOCS=	ffe.html
PLIST_FILES=	bin/ffe man/man1/ffe.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
