# Created by: kirk@strauser.com
# $FreeBSD$

PORTNAME=	bash-completion
PORTVERSION=	2.10
PORTEPOCH=	2
CATEGORIES=	shells

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programmable completion library for Bash

LICENSE=	GPLv2+

BROKEN_armv6=	fails to build: gmake: install-recursive: Error 1
BROKEN_armv7=	fails to build: gmake: install-recursive: Error 1

TEST_DEPENDS=	runtest:misc/dejagnu \
		${LOCALBASE}/lib/tcllib/cmdline/cmdline.tcl:devel/tcllib

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	CMAKE_MODULES DOCS FREEBSD
OPTIONS_SINGLE=	BASH
OPTIONS_SINGLE_BASH=	BASH_SHARED BASH_STATIC
OPTIONS_DEFAULT=BASH_SHARED CMAKE_MODULES FREEBSD
OPTIONS_SUB=	yes
BASH_SHARED_DESC=	Use shells/bash as backend
BASH_STATIC_DESC=	Use shells/bash-static as backend
CMAKE_MODULES_DESC=	Install bash-completion modules for cmake
FREEBSD_DESC=		Install completion functions for FreeBSD programs

NO_ARCH=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf gmake pathfix

SUB_FILES=	pkg-message
SUB_LIST=	RUNFILE=${DATADIR}/bash_completion.sh

GH_ACCOUNT=	scop
USE_GITHUB=	yes

BASH_SHARED_RUN_DEPENDS=bash:shells/bash
BASH_STATIC_RUN_DEPENDS=bash:shells/bash-static
FREEBSD_GH_TUPLE=	0mp:bash-completion-freebsd:1.1.1:freebsd/freebsd
FREEBSD_VARS=		LICENSE="BSD2CLAUSE GPLv2+" \
			LICENSE_COMB=multi \
			LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/freebsd/LICENSE \
			LICENSE_FILE_GPLv2+=${WRKSRC}/COPYING
FREEBSD_VARS_OFF=	LICENSE_FILE=${WRKSRC}/COPYING

post-patch:
	@${REINPLACE_CMD} \
		-e '/^profiledir =/ s|(sysconfdir)/profile.d|(prefix)/share/bash-completion|' \
		-e 's|\((datadir)/cmake\)|\1/Modules|' \
			${WRKSRC}/Makefile.am

post-configure:
	@${REINPLACE_CMD} \
		-e 's|/etc/ssl/openssl.cnf|${PREFIX}& &|g' \
		-e 's|/usr/lib\(/aspell\)|${PREFIX}/share\1|g' \
		-e 's|/usr/local|${PREFIX}|g' \
		-e 's|/usr/ports|${PORTSDIR}|g' \
		-e 's|/usr\(/sbin/postconf\)|${PREFIX}\1|g' \
		-e 's|/usr/share/info|&:${PREFIX}/info|g' \
		-e 's|/var\(/lib/rpm/macros\)|${PREFIX}\1|g' \
			${WRKSRC}/completions/*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES README.md doc/bash_completion.txt doc/bashrc doc/inputrc ${STAGEDIR}${DOCSDIR}/

post-install-FREEBSD-on:
	cd ${WRKSRC}/freebsd/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-test:
.for test in runCompletion runInstall runUnit
	-cd ${WRKSRC}/test && bash ${test}
.endfor

.include <bsd.port.mk>
