PORTNAME=	gurl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Terminal cURL-like HTTP tool with delightful JSON & header support
WWW=		https://github.com/skunkwerks/gurl

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	skunkwerks

GO_BUILDFLAGS=	-ldflags="-X github.com/skunkwerks/gurl/version.Version=${DISTVERSIONPREFIX}${DISTVERSION}"

PLIST_FILES=	bin/gurl \
		share/man/man1/gurl.1.gz

# The manual page is emitted by the freshly built binary itself, so the
# installed page and the running program can never disagree about options.
post-build:
	${GO_WRKDIR_BIN}/gurl -man > ${WRKSRC}/gurl.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gurl
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/gurl.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/gurl.1

.include <bsd.port.mk>
