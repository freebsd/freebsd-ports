PORTNAME=	shiori
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.4
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple bookmark manager built with Go
WWW=		https://github.com/go-shiori/shiori

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/go-shiori/shiori

SUB_LIST=	USER=${USERS:[1]} \
		HOMEDIR=${SHIORI_HOMEDIR}

USERS=		${SHIORI_USER}
GROUPS=		${SHIORI_GROUP}

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(${SHIORI_USER},${SHIORI_GROUP},0700) ${SHIORI_HOMEDIR}"

SHIORI_HOMEDIR=	/var/db/${SHIORI_USER}
SHIORI_USER=	${PORTNAME}
SHIORI_GROUP=	${SHIORI_USER}

BUILD_DATE=	%FT%T

# fix `shiori version` output
post-patch:
	${REINPLACE_CMD} \
		-e 's/"dev"/"${DISTVERSION}"/1' \
		-e 's/"none"/"${OPSYS}"/1' \
		-e 's/"unknown"/"${BUILD_DATE:gmtime}"/1' \
		${WRKSRC}/main.go \
		${WRKSRC}/internal/model/main.go

post-install:
	@${MKDIR} ${STAGEDIR}${SHIORI_HOMEDIR}

.include <bsd.port.mk>
