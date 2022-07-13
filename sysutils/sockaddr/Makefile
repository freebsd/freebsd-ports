PORTNAME=	sockaddr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line utility for querying IP information

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_PROJECT=	go-sockaddr
GH_TUPLE=	\
		armon:go-radix:7fddfc383310:armon_go_radix/vendor/github.com/armon/go-radix \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		golang:sys:11551d06cbcc:golang_sys/vendor/golang.org/x/sys \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:cli:v1.0.0:mitchellh_cli/vendor/github.com/mitchellh/cli \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		posener:complete:v1.1.1:posener_complete/vendor/github.com/posener/complete \
		ryanuber:columnize:v2.1.0:ryanuber_columnize/vendor/github.com/ryanuber/columnize

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.Version=${DISTVERSIONFULL} -s -w"

PLIST_FILES=	bin/sockaddr

.include <bsd.port.mk>
