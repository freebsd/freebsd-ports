PORTNAME=	su-exec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3
CATEGORIES=	security

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Switch user and group id and exec
WWW=		https://github.com/ncopa/su-exec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=			default static
default_CONFLICTS_INSTALL=	su-exec-static
static_PKGNAMESUFFIX=		-static
static_CONFLICTS_INSTALL=	su-exec

USE_GITHUB=	yes
GH_ACCOUNT=	ncopa

.if ${FLAVOR:U} == static
LDFLAGS+=	-static
.endif

PLIST_FILES=	bin/su-exec

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -o su-exec su-exec.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/su-exec ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
