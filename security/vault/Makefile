# $FreeBSD$

PORTNAME=	vault
PORTVERSION=	0.6.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for securely accessing secrets

LICENSE=	MPL

BUILD_DEPENDS=	go>=1.7.1:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

STRIP=		# stripping can break go binaries

USE_RC_SUBR=	vault

USERS=		vault
GROUPS=		vault

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/version/version.go

do-build:
	@cd ${WRKSRC}; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
