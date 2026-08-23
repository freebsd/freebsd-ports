PORTNAME=	protonmail-bridge
DISTVERSIONPREFIX=	v
DISTVERSION=	3.25.0
CATEGORIES=	mail

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Proton Mail Bridge for e-mail clients
WWW=		https://proton.me/mail/bridge

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libfido2.so:security/libfido2 \
		libsecret-1.so:security/libsecret

USES=		gettext-runtime gnome go:1.26+,modules pkgconfig ssl

GO_MODULE=	github.com/ProtonMail/proton-bridge/v3
GO_TARGET=	./cmd/Desktop-Bridge
GO_LDFLAGS=	-X ${CONSTANTS_PREFIX}.Version=${DISTVERSION} \
		-X ${CONSTANTS_PREFIX}.Revision=${COMMIT_HASH} \
		-X ${CONSTANTS_PREFIX}.Tag=${DISTVERSIONFULL} \
		-X ${CONSTANTS_PREFIX}.BuildTime=${:!${BUILD_TIME_CMD}!}

USE_GNOME=	glib20

BINARY_ALIAS=	sed=gsed

PLIST_FILES=	bin/${PORTNAME}

CONSTANTS_PREFIX=	github.com/ProtonMail/proton-bridge/v3/internal/constants
COMMIT_HASH=		f1f599e97167265cb0d10ad3d169269c324d9cc7
BUILD_TIME_CMD=		/bin/date -r $$(${AWK} '/TIMESTAMP/ { print $$NF }' ${DISTINFO_FILE}) '+%FT%T%z'

pre-build:
	cd ${WRKSRC}/utils && \
	${SETENV} ${MAKE_ENV} ${SH} ./credits.sh bridge

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/Desktop-Bridge \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}


.include <bsd.port.mk>
