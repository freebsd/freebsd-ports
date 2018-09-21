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
HASH=		4b26777
AST_COMMIT_DATE=	2018.09.20

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Development branch of AT&T KornShell 93

LICENSE=	EPL

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast
GH_TAGNAME=	${HASH}

CONFLICTS=	ksh93-*

USES=		meson ninja
FETCH_ENV=	HTTP_AUTH=basic:*:I\ accept\ www.opensource.org/licenses/cpl:.
LDFLAGS+=	-lm 
MESON_BUILD_DIR=	build
MAKE_ENV=	CCFLAGS="${CFLAGS}"

STATIC_MAKE_ENV=	LDFLAGS+=-static

BROKEN_aarch64=		Fails to compile: needs sbrk

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100093
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c
.endif
	@${MV} ${WRKSRC}/src/cmd/ksh93/ksh.1 ${WRKSRC}/src/cmd/ksh93/ksh93.1

do-test:
	cd ${WRKSRC}/src/cmd/ksh93/tests/ && ${SETENV} SHELL=${WRKSRC}/bin/ksh ${WRKSRC}/bin/ksh shtests

.include <bsd.port.post.mk>
