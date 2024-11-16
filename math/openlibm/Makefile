PORTNAME=	openlibm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High quality system independent, portable, open source libm
WWW=		http://julialang.org/openlibm/

LICENSE=	MIT ISCL BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_armv6=	fails to compile: a parameter list without types is only allowed in a function definition
BROKEN_armv7=	fails to compile: a parameter list without types is only allowed in a function definition

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	JuliaMath

.include <bsd.port.options.mk>

# Arch specific headers

.if ${ARCH} == amd64
PLIST_FILES=	include/openlibm/bsd_asm.h \
		include/openlibm/bsd_fpu.h \
		include/openlibm/bsd_ieeefp.h
.endif

.if ${ARCH} == i386
PLIST_FILES=	include/openlibm/bsd_asm.h \
		include/openlibm/bsd_ieeefp.h \
		include/openlibm/bsd_npx.h \
		include/openlibm/osx_asm.h
.endif

.include <bsd.port.mk>
