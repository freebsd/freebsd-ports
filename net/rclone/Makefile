# $FreeBSD$

PORTNAME=	rclone
PORTVERSION=	1.38
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Sync files to and from various cloud services

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	ncw
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
GH_TUPLE+=	\
		google:google-api-go-client:0caa379:googleapigoclient/src/google.golang.org/api \
		ncw:go-acd:56da839:goacd/src/github.com/ncw/go-acd \
		ncw:swift:b964f2c:swift/src/github.com/ncw/swift \
		aws:aws-sdk-go:87a2cff:awssdkgo/src/github.com/aws/aws-sdk-go \
		mreiferson:go-httpclient:31f0106:gohttpclient/src/github.com/mreiferson/go-httpclient \
		google:go-querystring:9235644:goquerystring/src/github.com/google/go-querystring \
		GoogleCloudPlatform:google-cloud-go:80a7732:gcloudgolang/src/cloud.google.com/go \
		golang:oauth2:3c3a985:oauth2/src/golang.org/x/oauth2 \
		golang:net:6d3beae:net/src/golang.org/x/net \
		golang:text:a7c0236:text/src/golang.org/x/text \
		skratchdot:open-golang:75fb7ed:opengolang/src/github.com/skratchdot/open-golang \
		stacktic:dropbox:58f839b:dropbox/src/github.com/stacktic/dropbox \
		tsenart:tb:19f4c3d:tb/src/github.com/tsenart/tb \
		VividCortex:ewma:c595cd8:ewma/src/github.com/VividCortex/ewma \
		golang:crypto:8e06e8d:crypto/src/golang.org/x/crypto \
		pkg:errors:a887431:errors/src/github.com/pkg/errors \
		bazil:fuse:371fbbd:fuse/src/bazil.org/fuse \
		spf13:cobra:9c28e4b:cobra/src/github.com/spf13/cobra \
		spf13:pflag:c7e63cf:pflag/src/github.com/spf13/pflag \
		rfjakob:eme:601d0e2:eme/src/github.com/rfjakob/eme \
		ogier:pflag:45c278a:opflag/src/github.com/ogier/pflag \
		Unknwon:goconfig:5aa4f8c:goconfig/src/github.com/Unknwon/goconfig \
		cpuguy83:go-md2man:a65d4d2:gomd2man/src/github.com/cpuguy83/go-md2man

PLIST_FILES=	bin/rclone

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
