PORTNAME=	ksh2020
PORTVERSION=	2020
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Development branch of AT&T KornShell 93

LICENSE=	EPL

USES=		compiler:c11 meson ninja python:build

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast
GH_TAGNAME=	ksh2020

KSH_CONFLICTS=		pdksh-*
KSH93_CONFLICTS=	ksh93-* ast-ksh-*

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
