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

PORTNAME=	ast-ksh
PORTVERSION=	${KSHVERSION:S/-//g}
CATEGORIES=	shells
DIST_SUBDIR=	ksh93

MAINTAINER=	saper@saper.info
COMMENT=	KornShell 93

LICENSE=	EPL

BROKEN_aarch64=		Fails to compile: needs sbrk

USES=		compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast
GH_TAGNAME=	ksh93v

# IMPORTANT:	Disabling conflicts, i.e. -DDISABLE_CONFLICTS will result in
#		arcane build failures due to already installed ksh/ksh93 in
#		$PATH.
CONFLICTS=	ksh93-*

OPTIONS_DEFINE=	EXAMPLES STATIC

LDFLAGS+=	-lm
MAKE_ENV=	CCFLAGS="-Wno-unused-value -Wno-parentheses -Wno-logical-op-parentheses ${CFLAGS}"

KSHVERSION=	2014-12-24

STATIC_MAKE_ENV=	LDFLAGS+=-static

post-patch:
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c

do-build:
	@cd ${WRKSRC}/ && ${SETENV} -i ${MAKE_ENV} ${SH} bin/package flat make ksh93

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ksh ${STAGEDIR}${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${WRKSRC}/man/man1/sh.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/ksh93.1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/fun/ && ${INSTALL_SCRIPT} dirs popd pushd ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/src/cmd/ksh93/tests/ && ${SETENV} SHELL=${WRKSRC}/bin/ksh ${WRKSRC}/bin/ksh shtests

.include <bsd.port.mk>
