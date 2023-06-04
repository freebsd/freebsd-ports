PORTNAME=	ocijail
PORTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Experimental, proof-of-concept OCI-compatible runtime for jails
WWW=		https://github.com/dfr/ocijail

LICENSE=	BSD3CLAUSE

IGNORE_FreeBSD_12= Not supported on FreeBSD 12 (uses c++20)

BUILD_DEPENDS=	bazel:devel/bazel5 bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	dfr
GH_TAGNAME=	v0.1

PLIST_FILES=	bin/ocijail

# Build happens in the //:install rule
NO_BUILD=	yes
BAZEL_OPTS=	--batch --output_user_root=${WRKDIR}/bazel_out

do-install:
	cd ${WRKSRC} && bazel ${BAZEL_OPTS} run --experimental_repository_disable_download //:install -- ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
