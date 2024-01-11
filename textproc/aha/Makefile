PORTNAME=	aha
DISTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	textproc devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ansi HTML Adapter
WWW=		https://github.com/theZiz/aha

LICENSE=	LGPL20+ MPL11
LICENSE_COMB=	dual

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	theZiz

MAKE_ARGS=	MANDIR="${PREFIX}/share/man"
PLIST_FILES=	bin/aha \
		share/man/man1/aha.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aha

.include <bsd.port.mk>
