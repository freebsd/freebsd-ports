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
HASH=		228ed74
AST_COMMIT_DATE=	2018.12.19

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Development branch of AT&T KornShell 93

LICENSE=	EPL

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast
GH_TAGNAME=	${HASH}

KSH93_CONFLICTS=	ksh93-*
KSH_CONFLICTS=		pdksh-*

USES=		meson ninja
FETCH_ENV=	HTTP_AUTH=basic:*:I\ accept\ www.opensource.org/licenses/cpl:.
LDFLAGS+=	-lm 
MESON_BUILD_DIR=	build
MAKE_ENV=	CCFLAGS="${CFLAGS}"

STATIC_MAKE_ENV=	LDFLAGS+=-static

BROKEN_aarch64=		Fails to compile: needs sbrk

OPTIONS_DEFAULT=	KSH93
OPTIONS_SINGLE=		BIN_KSH
OPTIONS_SINGLE_BIN_KSH=	KSH KSH93
KSH_DESC=		Install to ${PREFIX}/bin/ksh
KSH93_DESC=		Install to ${PREFIX}/bin/ksh93

KSH93_EXTRA_PATCHES=	${FILESDIR}/extra-patch-install-as-ksh93
KSH93_DESC=	Install to ${PREFIX}/bin/ksh93

KSH_PLIST_SUB=		93=""
KSH93_PLIST_SUB=	93="93"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c
.if ${PORT_OPTIONS:MKSH93}
	@${MV} ${WRKSRC}/src/cmd/ksh93/ksh.1 ${WRKSRC}/src/cmd/ksh93/ksh93.1
.endif

.include <bsd.port.mk>
