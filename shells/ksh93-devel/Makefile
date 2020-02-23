# $FreeBSD$

# Make sure that your configuration DOES NOT set ANY gcc-related
# variables.  ksh93 will not compile if you set even the seemingly
# most unrelated variable related to gcc configuration.  This means
# especially any flag which attempts to set the cputype.  Setting the
# cputype does absolutely nothing except cause systems to fail in
# horrible ways.  For any modern processor, setting the cputype only
# serves to expose gcc bugs and does nothing to speed up any known
# program.  If you are really unconvinced, go ahead but do not
# complain to me about it.

PORTNAME=	ksh93
PORTVERSION=	${AST_COMMIT_DATE}
CATEGORIES=	shells
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	ksh93

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Development branch of AT&T KornShell 93

LICENSE=	EPL

HASH=		0be82553
AST_COMMIT_DATE=	2020.02.22

BROKEN_aarch64=		Fails to compile: needs sbrk

USES=		compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast
GH_TAGNAME=	${HASH}

# IMPORTANT:	Disabling conflicts, i.e. -DDISABLE_CONFLICTS will result in
#		arcane build failures due to already installed ksh/ksh93 in
#		$PATH.
KSH_CONFLICTS=		pdksh-*
KSH93_CONFLICTS=	ksh93-2* ast-ksh-*

OPTIONS_DEFAULT=	KSH93 EXAMPLES
OPTIONS_DEFINE=		EXAMPLES STATIC
OPTIONS_SINGLE=		BIN_KSH
OPTIONS_SINGLE_BIN_KSH=	KSH KSH93
KSH_DESC=		Install to ${PREFIX}/bin/ksh
KSH93_DESC=		Install to ${PREFIX}/bin/ksh93

CFLAGS+=	-DMAP_TYPE
LDFLAGS+=	-lm
MAKE_ENV=	CCFLAGS="-Wno-unused-value -Wno-parentheses -Wno-logical-op-parentheses" CFLAGS="${CFLAGS}"

STATIC_MAKE_ENV=	LDFLAGS+=-static

KSH_PLIST_SUB=		93=""
KSH93_PLIST_SUB=	93="93"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKSH93}
PNAME=		ksh93
.else
PNAME=		ksh
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c

do-build:
	@cd ${WRKSRC}/ && ${SETENV} -i ${MAKE_ENV} ${SH} bin/package flat make ksh93

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ksh ${STAGEDIR}${PREFIX}/bin/${PNAME}
	${INSTALL_MAN} ${WRKSRC}/man/man1/sh.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${PNAME}.1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/fun/ && ${INSTALL_SCRIPT} dirs popd pushd ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/src/cmd/ksh93/tests/ && ${SETENV} SHELL=${WRKSRC}/bin/ksh ${WRKSRC}/bin/ksh shtests

.include <bsd.port.mk>
