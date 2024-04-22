PORTNAME=	basic-stats
DISTVERSION=	0.1.2-8
DISTVERSIONSUFFIX=	-g338a259
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command-line tool to perform basic statistics on tabular data
WWW=		https://github.com/auerlab/basic-stats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ENV=	MANDIR=${PREFIX}/share/man

INSTALL_TARGET=	install-strip

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend

.include <bsd.port.mk>
