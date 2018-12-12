# $FreeBSD$

PORTNAME=	ipdbtools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	cyclaero@gmail.com
COMMENT=	Tools for IP based Geo-blocking and Geo-routing

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	cyclaero
GH_PROJECT=	ipdb

PLIST_FILES=	bin/ipup \
		bin/ipdb \
		bin/ipdb-update.sh \
		man/man1/ipdbtools.1.gz \
		man/man1/ipup.1.gz \
		man/man1/ipdb.1.gz \
		man/man1/ipdb-update.sh.1.gz

.include <bsd.port.mk>
