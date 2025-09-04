PORTNAME=	tusc
DISTVERSION=	0.4.7
PORTREVISION=	29
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	TUS Command line client and server
WWW=		https://github.com/jackhftang/tusc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	jackhftang
GH_TUPLE=	\
		Acconut:lockfile:v1.1.0:acconut_lockfile/vendor/gopkg.in/Acconut/lockfile.v1 \
		bmizerany:pat:6226ea591a40:bmizerany_pat/vendor/github.com/bmizerany/pat \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt_go \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eventials:go-tus:9db47421f6a0:eventials_go_tus/vendor/github.com/eventials/go-tus \
		golang:net:da137c7871d7:golang_net/vendor/golang.org/x/net \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tus:tusd:30811b6579c5:tus_tusd/vendor/github.com/tus/tusd

GO_TARGET=	cmd/tusc.go:tusc

PLIST_FILES=	bin/tusc

post-extract:
	( cd ${WRKSRC} && ${MV} vendor/github.com/docopt/docopt_go \
		vendor/github.com/docopt/docopt-go )

.include <bsd.port.mk>
