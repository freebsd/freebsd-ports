PORTNAME=	kopia
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast and secure open-source backup/restore tool
WWW=		https://kopia.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/kopia/kopia
GO_BUILDFLAGS=	-ldflags "\
		-X github.com/kopia/kopia/repo.BuildVersion=${DISTVERSION} \
		-X github.com/kopia/kopia/repo.BuildInfo="`date +%Y%m%d`""

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-build:
	${GO_WRKDIR_BIN}/${PORTNAME} --log-dir="" --help-man > ${WRKSRC}/${PORTNAME}.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
