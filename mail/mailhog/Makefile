PORTNAME=	mailhog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	28
CATEGORIES=	mail devel

MAINTAINER=	mops@punkt.de
COMMENT=	MailHog development mail server
WWW=		https://github.com/mailhog/MailHog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go
USE_RC_SUBR=	mailhog
USE_GITHUB=	yes
GH_PROJECT=	MailHog
GH_SUBDIR=	src/github.com/mailhog/MailHog
GH_TUPLE=	gorilla:pat:64353c3:pat/vendor/github.com/gorilla/pat \
		gorilla:context:8559d4a:context/vendor/github.com/gorilla/context \
		gorilla:mux:91708ff:mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:78cf1bc:websocket/vendor/github.com/gorilla/websocket \
		ian-kent:go-log:5731446:go_log/vendor/github.com/ian-kent/go-log \
		ian-kent:goose:c3541ea:goose/vendor/github.com/ian-kent/goose \
		ian-kent:envconf:c198099:envconf/vendor/github.com/ian-kent/envconf \
		ian-kent:linkio:97566b8:linkio/vendor/github.com/ian-kent/linkio \
		mailhog:data:v${DISTVERSION}:data/vendor/github.com/mailhog/data \
		mailhog:http:v${DISTVERSION}:http/vendor/github.com/mailhog/http \
		mailhog:mhsendmail:9e70164:mhsendmail/vendor/github.com/mailhog/mhsendmail \
		mailhog:smtp:v${DISTVERSION}:smtp/vendor/github.com/mailhog/smtp \
		mailhog:storage:v${DISTVERSION}:storage/vendor/github.com/mailhog/storage \
		mailhog:MailHog-Server:v${DISTVERSION}:mailhog_server/vendor/github.com/mailhog/MailHog-Server \
		mailhog:MailHog-UI:v${DISTVERSION}:mailhog_ui/vendor/github.com/mailhog/MailHog-UI \
		t-k:fluent-logger-golang:0f8ec08:fluent_logger_golang/vendor/github.com/t-k/fluent-logger-golang \
		tinylib:msgp:e818a18:msgp/vendor/github.com/tinylib/msgp \
		philhofer:fwd:8be6da3:fwd/vendor/github.com/philhofer/fwd \
		golang:crypto:eb4f295:crypto/vendor/golang.org/x/crypto \
		go-mgo:mgo:a6b53ec:mgo/vendor/gopkg.in/mgo.v2

GO_TARGET=	:mailhog

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

.include <bsd.port.mk>
