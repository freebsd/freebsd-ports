PORTNAME=	ocijail
DISTVERSION=	0.1.rc1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Experimental, proof-of-concept OCI-compatible runtime for jails
WWW=		https://github.com/dfr/ocijail

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bazel:devel/bazel bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	dfr
GH_TAGNAME=	v0.1rc1

PLIST_FILES=	bin/ocijail

# Build happens in the //:install rule
NO_BUILD=	yes
BAZEL_OPTS=	--batch --output_user_root=${WRKDIR}/bazel_out

do-install:
	cd ${WRKSRC} && bazel ${BAZEL_OPTS} run --experimental_repository_disable_download //:install -- ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
