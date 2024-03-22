PORTNAME=	npmount
DISTVERSION=	0.1.1-3
DISTVERSIONSUFFIX=	-ge0c8050
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line tool for non-privileged [un]mount
WWW=		https://github.com/outpaddling/npmount

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxtend>=0.2.0:devel/libxtend
LIB_DEPENDS=	libxtend.so:devel/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

MAKE_ENV=	MANDIR=${PREFIX}/share/man

WITH_DEBUG=	yes

.include <bsd.port.mk>
