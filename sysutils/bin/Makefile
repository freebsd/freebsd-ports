PORTNAME=	bin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Effortless binary manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	marcosnils

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'main.version=${DISTVERSIONFULL}' \
			-X 'main.commit=${GITID}' \
			-X 'main.date=${BUILD_DATE}' \
			-X 'main.BuiltBy=FreeBSD Ports'"
CGO_ENABLED=	0

PLIST_FILES=	bin/${PORTNAME}
#
# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse --short HEAD'
# in the Bin repository to get the value of GITID.
GITID=		9ae5fec462fcbe33a1388a6cd651f22ee845ac2b

BUILD_DATE=	$$(date -u "+%Y-%m-%dT%H:%M:%SZ")

.include <bsd.port.mk>
