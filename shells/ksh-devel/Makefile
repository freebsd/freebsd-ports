PORTNAME=	ksh
PORTVERSION=	${AST_COMMIT_DATE}
CATEGORIES=	shells
PKGNAMESUFFIX=	-devel

MAINTAINER=	cy@FreeBSD.org
COMMENT=	ksh93u+m is the development branch ksh93 based on AT&T ksh93u+ (stable)
WWW=		https://github.com/ksh93/ksh

LICENSE=		EPL
LICENSE_FILE=		${WRKSRC}/COPYRIGHT
LICENSE_FILE_EPL=	${WRKSRC}/LICENSE.md

HASH=			a215b8be
AST_COMMIT_DATE=	2026.03.02

USES=		compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	ksh93
GH_PROJECT=	ksh
GH_TAGNAME=	${HASH}

KSH_CONFLICTS=		pdksh
KSH93_CONFLICTS=	ksh93 ast-ksh
KSH93D_CONFLICTS=	ast-ksh

OPTIONS_DEFAULT=	KSH93 EXAMPLES
OPTIONS_DEFINE=		EXAMPLES STATIC
OPTIONS_SINGLE=		BIN_KSH
OPTIONS_SINGLE_BIN_KSH=	KSH KSH93 KSH93D
KSH_DESC=		Install to ${PREFIX}/bin/ksh
KSH93_DESC=		Install to ${PREFIX}/bin/ksh93
KSH93D_DESC=		Install to ${PREFIX}/bin/ksh93d (development)

STATIC_MAKE_ENV=	AST_NO_DYLIB="y"
MAKE_ENV=		CCFLAGS="${CFLAGS}"

STATIC_PLIST_SUB=	DYNAMIC="@comment "
STATIC_PLIST_SUB_OFF=	DYNAMIC=""

KSH_PLIST_SUB=		93=""
KSH93_PLIST_SUB=	93="93"
KSH93D_PLIST_SUB=	93="93d"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKSH93D}
PSUFFIX=	93d
.elif ${PORT_OPTIONS:MKSH93}
PSUFFIX=	93
.endif

do-build:
	@cd ${WRKSRC}/ && ${SETENV} -i ${MAKE_ENV} ${SH} bin/package make -j${MAKE_JOBS_NUMBER} SHELL=${SH}

do-install:
	@cd ${WRKSRC}/ && \
	${SETENV} -i ${MAKE_ENV} ${SH} bin/package install ${PREFIX} DESTDIR=${STAGEDIR} SHELL=${SH} && \
	mv ${STAGEDIR}${PREFIX}/bin/ksh ${STAGEDIR}${PREFIX}/bin/ksh${PSUFFIX} && \
	mv ${STAGEDIR}${PREFIX}/share/man/man1/ksh.1 ${STAGEDIR}${PREFIX}/share/man/man1/ksh${PSUFFIX}.1 && \
	ln -s ../fun ${STAGEDIR}${EXAMPLESDIR}${PSUFFIX}

do-test:
	@cd ${WRKSRC}/ && bin/shtests

.include <bsd.port.mk>
