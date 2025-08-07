PORTNAME=	teleirc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	16
CATEGORIES=	net-im

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Telegram/IRC bridge for use with any IRC channel and Telegram group
WWW=		https://teleirc.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	ritlug

GH_TUPLE=	caarlos0:env:v6.0.0:caarlos0_env_v6/vendor/github.com/caarlos0/env/v6 \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-playground:assert:v1.2.1:go_playground_assert/vendor/gopkg.in/go-playground/assert.v1 \
		go-playground:locales:v0.12.1:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.16.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v9.29.1:go_playground_validator/vendor/github.com/go-playground/validator \
		go-telegram-bot-api:telegram-bot-api:v4.6.4:go_telegram_bot_api_telegram_bot_api/vendor/github.com/go-telegram-bot-api/telegram-bot-api \
		golang:mock:v1.4.3:golang_mock/vendor/github.com/golang/mock \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		kyokomi:emoji:v2.1.0:kyokomi_emoji/vendor/github.com/kyokomi/emoji \
		leodido:go-urn:v1.1.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		lrstanley:girc:4fc93959e1a7:lrstanley_girc/vendor/github.com/lrstanley/girc \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		technoweenie:multipartstreamer:v1.0.1:technoweenie_multipartstreamer/vendor/github.com/technoweenie/multipartstreamer
USE_RC_SUBR=	teleirc

GO_TARGET=	./cmd/teleirc.go:teleirc
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

USERS=		teleirc
GROUPS=		teleirc

PLIST_SUB=	GROUP="${GROUPS:[0]}" \
		USER="${USERS:[0]}"

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc
	@${CP} ${WRKSRC}/env.example ${STAGEDIR}/${PREFIX}/etc/teleirc.conf.sample

.include <bsd.port.mk>
