PORTNAME=	librespeed-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	net www

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	CLI interface to run librespeed speedtests

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/librespeed/speedtest-cli
GO_BUILDFLAGS+=	-ldflags "-X \"librespeed-cli/defs.ProgName=${PORTNAME}\" \
		-X \"librespeed-cli/defs.ProgVersion=${PORTVERSION}-freebsd\" \
		-X \"librespeed-cli/defs.BuildDate=`date -u '+%Y-%m-%d %H:%M:%S %Z'`\""

PLIST_FILES=	bin/librespeed-cli

.include <bsd.port.mk>
