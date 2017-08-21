# Created by: punkt.de Hosting Team <mops@punkt.de>
# $FreeBSD$

PORTNAME=	mailhog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	mail devel

MAINTAINER=	mops@punkt.de
COMMENT=	MailHog development mail server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go
USE_RC_SUBR=	mailhog
USE_GITHUB=	yes
GH_ACCOUNT=	mailhog
GH_PROJECT=	MailHog
GH_SUBDIR=	src/github.com/mailhog/MailHog
GH_TUPLE=	gorilla:pat:cf955c3:pat/src/github.com/gorilla/pat \
		gorilla:context:08b5f42:context/src/github.com/gorilla/context \
		gorilla:mux:ac112f7:mux/src/github.com/gorilla/mux \
		gorilla:websocket:a69d9f6:websocket/src/github.com/gorilla/websocket \
		ian-kent:go-log:5731446:go_log/src/github.com/ian-kent/go-log \
		ian-kent:goose:c3541ea:goose/src/github.com/ian-kent/goose \
		ian-kent:envconf:c198099:envconf/src/github.com/ian-kent/envconf \
		ian-kent:linkio:97566b8:linkio/src/github.com/ian-kent/linkio \
		mailhog:data:v${DISTVERSION}:data/src/github.com/mailhog/data \
		mailhog:http:v${DISTVERSION}:http/src/github.com/mailhog/http \
		mailhog:mhsendmail:9e70164:mhsendmail/src/github.com/mailhog/mhsendmail \
		mailhog:smtp:v${DISTVERSION}:smtp/src/github.com/mailhog/smtp \
		mailhog:storage:v${DISTVERSION}:storage/src/github.com/mailhog/storage \
		mailhog:MailHog-Server:v${DISTVERSION}:mailhog_server/src/github.com/mailhog/MailHog-Server \
		mailhog:MailHog-UI:v${DISTVERSION}:mailhog_ui/src/github.com/mailhog/MailHog-UI \
		t-k:fluent-logger-golang:0f8ec08:fluent_logger_golang/src/github.com/t-k/fluent-logger-golang \
		tinylib:msgp:701aacd:msgp/src/github.com/tinylib/msgp \
		philhofer:fwd:1612a29:fwd/src/github.com/philhofer/fwd \
		golang:crypto:eb71ad9:crypto/src/golang.org/x/crypto \
		go-mgo:mgo:3f83fa5:mgo/src/gopkg.in/mgo.v2

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

post-extract:
	@${LN} -sf ${WRKSRC}/src ${WRKDIR}
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}

.include <bsd.port.mk>
