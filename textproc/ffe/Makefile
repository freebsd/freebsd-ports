# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffe
DISTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/ff-extractor/ff-extractor/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flat file extractor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo localbase
GNU_CONFIGURE=	yes

INFO=		ffe
PORTDOCS=	ffe.html
PLIST_FILES=	bin/ffe man/man1/ffe.1.gz

OPTIONS_DEFINE=		DOCS GCRYPT
GCRYPT_CONFIGURE_WITH=	libgcrypt-prefix="${LOCALBASE}"
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

.include <bsd.port.mk>
