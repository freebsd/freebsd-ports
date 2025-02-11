PORTNAME=	xml-format
DISTVERSION=	0.2.0-3
DISTVERSIONSUFFIX=	-g4448d89
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	XML beautifier
WWW=		https://github.com/outpaddling/xml-format

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libxtend.so:devel/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ENV+=	DATADIR=${DATADIR} MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
