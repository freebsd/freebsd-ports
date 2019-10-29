# $FreeBSD$

PORTNAME=	ksh93
PORTVERSION=	${AST_COMMIT_DATE}
CATEGORIES=	shells
PKGNAMESUFFIX=	-devel

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Development branch of AT&T KornShell 93

LICENSE=	EPL

USES=		compiler:c11 meson ninja python:build

HASH=		4503830a
AST_COMMIT_DATE=	2019.10.29

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast
GH_TAGNAME=	${HASH}

KSH_CONFLICTS=		pdksh-*
KSH93_CONFLICTS=	ksh93-2* ast-ksh-*

MESON_BUILD_DIR=	build

OPTIONS_DEFAULT=	KSH93
OPTIONS_SINGLE=		BIN_KSH
OPTIONS_SINGLE_BIN_KSH=	KSH KSH93
KSH_DESC=		Install to ${PREFIX}/bin/ksh
KSH93_DESC=		Install to ${PREFIX}/bin/ksh93

KSH93_EXTRA_PATCHES=	${FILESDIR}/extra-patch-install-as-ksh93 \
			${FILESDIR}/extra-patch-install-as-ksh93-doc

KSH_PLIST_SUB=		93=""
KSH93_PLIST_SUB=	93="93"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/for name in/ s|python.*|${PYTHON_CMD}|g' ${WRKSRC}/scripts/python.sh
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c
.if ${PORT_OPTIONS:MKSH93}
	@${MV} ${WRKSRC}/src/cmd/ksh93/docs/ksh.1 ${WRKSRC}/src/cmd/ksh93/docs/ksh93.1
.endif
.if ${PORT_OPTIONS:MKSH}
	@# Keep portlint happy
.endif

.include <bsd.port.mk>
