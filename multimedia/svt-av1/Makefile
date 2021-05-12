PORTNAME=	svt-av1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	284ef885f85f.patch:-p1 # https://gitlab.com/AOMediaCodec/SVT-AV1/-/merge_requests/1704

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scalable AV1 encoder

LICENSE=	BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE.md
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/third_party/fastfeat/LICENSE
LICENSE_FILE_MIT=		${WRKSRC}/third_party/safestringlib/LICENSE

BROKEN_i386=	https://gitlab.com/AOMediaCodec/SVT-AV1/-/issues/1231

BUILD_DEPENDS=	nasm:devel/nasm

USES=		cmake compiler:c11
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_ACCOUNT=	AOMediaCodec
GL_PROJECT=	SVT-AV1
GL_COMMIT=	3971c982311d49f9355dc8dccdcf8d21b70fa624
CMAKE_ON=	ENABLE_NASM
CMAKE_OFF=	NATIVE

OPTIONS_DEFINE=	LTO
OPTIONS_DEFAULT=LTO
OPTIONS_EXCLUDE_powerpc64=	${"${/usr/bin/ld:L:tA}"==/usr/bin/ld.lld:?LTO:} # LLVM bug 47353

LTO_CMAKE_BOOL=		CMAKE_INTERPROCEDURAL_OPTIMIZATION
LTO_CMAKE_ON=		-DCMAKE_POLICY_DEFAULT_CMP0069:STRING=NEW
.if exists(/usr/bin/ld.lld) && ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --plugin isn't supported by old GNU ld.bfd in base
LTO_LDFLAGS=		-fuse-ld=lld
.endif

.include <bsd.port.mk>
