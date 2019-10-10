# $FreeBSD$

PORTNAME=	ksh93
DISTVERSION=	2020.0.0
PORTEPOCH=	1
CATEGORIES=	shells

MAINTAINER=	cy@freebsd.org
COMMENT=	AT&T KornShell 93

LICENSE=	EPL

USES=		compiler:c11 meson ninja python:build

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast

KSH_CONFLICTS=		pdksh-*
KSH93_CONFLICTS=	ksh93-devel-* ast-ksh-*

MESON_BUILD_DIR=	build

OPTIONS_DEFAULT=	KSH93
OPTIONS_SINGLE=		BIN_KSH
OPTIONS_SINGLE_BIN_KSH=	KSH KSH93
KSH_DESC=		Install to ${PREFIX}/bin/ksh
KSH93_DESC=		Install to ${PREFIX}/bin/ksh93

KSH93_EXTRA_PATCHES=	${FILESDIR}/extra-patch-install-as-ksh93

KSH_PLIST_SUB=		93=""
KSH93_PLIST_SUB=	93="93"

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} >= 90
BROKEN=	GCC 9.1 changes the output of `gcc -E` which breaks the conf.sh script, fixed in shells/ksh93-devel
.endif

post-patch:
	@${REINPLACE_CMD} -e '/for name in/ s|python.*|${PYTHON_CMD}|g' ${WRKSRC}/scripts/python.sh
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c
.if ${PORT_OPTIONS:MKSH93}
	@${MV} ${WRKSRC}/src/cmd/ksh93/docs/ksh.1 ${WRKSRC}/src/cmd/ksh93/docs/ksh93.1
.endif
.if ${PORT_OPTIONS:MKSH}
	@# Keep portlint happy
.endif

.include <bsd.port.post.mk>
