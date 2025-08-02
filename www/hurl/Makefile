PORTNAME=	hurl
DISTVERSION=	7.0.0
CATEGORIES=	www

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	CLI to run HTTP requests defined in a simple plain text format
WWW=		https://hurl.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo gnome ssl llvm
USE_GITHUB=	yes
GH_ACCOUNT=	Orange-OpenSource
USE_GNOME=	libxml2

CARGO_INSTALL_PATH=	packages/hurl packages/hurlfmt

PLIST_FILES=	bin/hurl \
		bin/hurlfmt \
		share/man/man1/hurl.1.gz \
		share/man/man1/hurlfmt.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manual/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
