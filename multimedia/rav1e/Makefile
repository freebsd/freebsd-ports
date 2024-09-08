PORTNAME=	rav1e
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION?=	5
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast and safe AV1 encoder
WWW=		https://github.com/xiph/rav1e

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	xiph
PLIST_FILES?=	bin/${PORTNAME}

post-patch:
# Extract (snapshot) version from the port instead of CARGO_PKG_VERSION
	@${REINPLACE_CMD} -e 's/\<.*GIT_VERSION\.unwrap.*/"${DISTVERSIONFULL}"/' \
		-e $$'/GIT_VERSION/,/UNKNOWN/c\\\n\t"${DISTVERSIONFULL}",\n' \
		${WRKSRC}/src/bin/common.rs ${WRKSRC}/src/lib.rs

.if !target(post-install)
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

.include <bsd.port.mk>
