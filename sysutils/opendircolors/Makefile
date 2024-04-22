PORTNAME=	opendircolors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	me@cameronkatri.com
COMMENT=	BSD-licensed replacement for dircolors
WWW=		https://github.com/CRKatri/opendircolors

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	CRKatri

MAKE_ENV=	BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/share/man/man"

CONFLICTS_INSTALL=	gnuls # bin/dircolors

.include <bsd.port.mk>
