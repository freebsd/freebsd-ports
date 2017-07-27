# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drive
PORTVERSION=	0.3.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny program to pull or push Google Drive files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	${GO_PKGNAME}/cmd/${GH_PROJECT}
USES=		go

PLIST_FILES=	bin/drive

GH_ACCOUNT=	odeke-em
GH_TUPLE=	boltdb:bolt:v1.3.1:boltdb_bolt/../src/github.com/boltdb/bolt \
		cheggaaa:pb:v2.0.4:cheggaaa_pb/../src/github.com/cheggaaa/pb \
		fatih:color:v1.5.0:fatih_color/../src/github.com/fatih/color \
		golang:crypto:6914964:golang_crypto/../src/golang.org/x/crypto \
		golang:net:ab54850:golang_net/../src/golang.org/x/net \
		golang:oauth2:b53b38a:golang_oauth2/../src/golang.org/x/oauth2 \
		google:google-api-go-client:295e4bb:google_googleapigoclient/../src/google.golang.org/api \
		GoogleCloudPlatform:google-cloud-go:v0.10.0:GoogleCloudPlatform_googlecloudgo/../src/cloud.google.com/go \
		mattn:go-colorable:v0.0.8:mattn_gocolorable/../src/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.2:mattn_goisatty/../src/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:mattn_gorunewidth/../src/github.com/mattn/go-runewidth \
		odeke-em:cache:baf8e43:odekeem_cache/../src/github.com/odeke-em/cache \
		odeke-em:cli-spinner:610063b:odekeem_clispinner/../src/github.com/odeke-em/cli-spinner \
		odeke-em:command:91ca5ec:odekeem_command/../src/github.com/odeke-em/command \
		odeke-em:exponential-backoff:96e25d3:odekeem_exponential_backoff/../src/github.com/odeke-em/exponential-backoff \
		odeke-em:extractor:801861a:odekeem_extractor/../src/github.com/odeke-em/extractor \
		odeke-em:go-utils:e8ebaed:odekeem_go_utils/../src/github.com/odeke-em/go-utils \
		odeke-em:go-uuid:b211d76:odekeem_gouuid/../src/github.com/odeke-em/go-uuid \
		odeke-em:log:8d60a69:odekeem_log/../src/github.com/odeke-em/log \
		odeke-em:meddler:d2b51d2:odekeem_meddler/../src/github.com/odeke-em/meddler \
		odeke-em:namespace:0ab79ba:odekeem_namespace/../src/github.com/odeke-em/namespace \
		odeke-em:pretty-words:9d37a7f:odekeem_prettywords/../src/github.com/odeke-em/pretty-words \
		odeke-em:semalim:9c88bf5:odekeem_semalim/../src/github.com/odeke-em/semalim \
		odeke-em:statos:292960a:odekeem_statos/../src/github.com/odeke-em/statos \
		skratchdot:open-golang:75fb7ed:skratchdot_opengolang/../src/github.com/skratchdot/open-golang \
		VividCortex:ewma:v1.1:VividCortex_ewma/../src/github.com/VividCortex/ewma
USE_GITHUB=	yes

post-patch:
	@${MKDIR} ${GO_WRKDIR_SRC}/gopkg.in/cheggaaa/
	@${LN} -s ${GO_WRKDIR_SRC}/github.com/cheggaaa/pb ${GO_WRKDIR_SRC}/gopkg.in/cheggaaa/pb.v2
	@${MKDIR} ${GO_WRKDIR_SRC}/gopkg.in/fatih/
	@${LN} -s ${GO_WRKDIR_SRC}/github.com/fatih/color ${GO_WRKDIR_SRC}/gopkg.in/fatih/color.v1
	@${MKDIR} ${GO_WRKDIR_SRC}/gopkg.in/mattn/
	@${LN} -s ${GO_WRKDIR_SRC}/github.com/mattn/go-colorable ${GO_WRKDIR_SRC}/gopkg.in/mattn/go-colorable.v0
	@${LN} -s ${GO_WRKDIR_SRC}/github.com/mattn/go-isatty ${GO_WRKDIR_SRC}/gopkg.in/mattn/go-isatty.v0
	@${LN} -s ${GO_WRKDIR_SRC}/github.com/mattn/go-runewidth ${GO_WRKDIR_SRC}/gopkg.in/mattn/go-runewidth.v0
	@${MKDIR} ${GO_WRKDIR_SRC}/gopkg.in/VividCortex/
	@${LN} -s ${GO_WRKDIR_SRC}/github.com/VividCortex/ewma ${GO_WRKDIR_SRC}/gopkg.in/VividCortex/ewma.v1

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/drive ${STAGEDIR}${PREFIX}/bin/drive

.include <bsd.port.mk>
