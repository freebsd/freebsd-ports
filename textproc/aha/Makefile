# $FreeBSD$

PORTNAME=	aha
DISTVERSION=	0.5.1
CATEGORIES=	textproc devel

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Ansi HTML Adapter

LICENSE=	LGPL20+ MPL11
LICENSE_COMB=	dual

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	theZiz

MAKE_ARGS=	MANDIR="${MANPREFIX}/man"
PLIST_FILES=	bin/aha \
		man/man1/aha.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aha

.include <bsd.port.mk>
