# $FreeBSD$

PORTNAME=	caronade
DISTVERSIONPREFIX=v
DISTVERSION=	0.4.0
CATEGORIES=	ports-mgmt

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Small and light tool to help with FreeBSD Ports CI

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sassc:textproc/sassc

USES=		go:modules,no_targets
USE_RC_SUBR=	caronade

USE_GITHUB=	yes
GH_ACCOUNT=	decke

MAKE_ENV+=	GO_BUILDFLAGS="${GO_BUILDFLAGS}"

GH_TUPLE=	\
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:62affa334b73:golang_net/vendor/golang.org/x/net \
		golang:sys:aee5d888a860:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		labstack:echo:v4.1.17:labstack_echo_v4/vendor/github.com/labstack/echo/v4 \
		labstack:gommon:v0.3.0:labstack_gommon/vendor/github.com/labstack/gommon \
		mattn:go-colorable:v0.1.7:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		unrolled:secure:v1.0.8:unrolled_secure/vendor/github.com/unrolled/secure \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.2.1:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate

.include <bsd.port.mk>
