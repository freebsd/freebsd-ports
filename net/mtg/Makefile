PORTNAME=	mtg
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.8
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	MTPROTO proxy server for Telegram
WWW=		https://github.com/9seconds/mtg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/9seconds/mtg/v2
GO_BUILDFLAGS+=	-ldflags "-s -w -X main.version=${DISTVERSION}" -tags netgo

MTG_USER?=	${WWWOWN}
MTG_GROUP?=	${WWWGRP}

SUB_LIST+=	USER=${MTG_USER} \
		GROUP=${MTG_GROUP}

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(${MTG_USER},${MTG_GROUP},750) ${ETCDIR}" \
		"@sample(${MTG_USER},${MTG_GROUP},640) ${ETCDIR}/config.toml.sample"

.include <bsd.port.pre.mk>

.if ${MTG_USER} == ${WWWOWN}
USERS=		${MTG_USER}
.endif
.if ${MTG_GROUP} == ${WWWGRP}
GROUPS=		${MTG_GROUP}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/example.config.toml \
		${STAGEDIR}${ETCDIR}/config.toml.sample

.include <bsd.port.post.mk>
