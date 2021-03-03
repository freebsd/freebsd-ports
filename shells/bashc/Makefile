# Created by: Igor Pokrovsky <ip@unixway.org>
# $FreeBSD$

PORTNAME=	bashc
PORTVERSION=	5.0.9
CATEGORIES=	shells

MAINTAINER=	ip@unixway.org
COMMENT=	GNU Bourne Again shell extended with two-panel file manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison cpe gmake iconv localbase makeinfo pathfix
GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes
CPE_VENDOR=	gnu

USE_GITHUB=	yes
GH_ACCOUNT=	sergev
GH_PROJECT=	bash-commander
GH_TAGNAME=	f707afab3e299d9b9e557923d355e14d2fe1291a

OPTIONS_DEFINE=	DOCS FDESCFS HELP NLS STATIC SYSBASHRC SYSLOG
FDESCFS_DESC=	Enable use of /dev/fd
HELP_DESC=	Enable builtin help
SYSBASHRC_DESC=	Enable system-wide rc files

OPTIONS_DEFAULT=	HELP

FDESCFS_CONFIGURE_ENV_OFF=	bash_cv_dev_fd=absent

HELP_CONFIGURE_ENABLE=	help-builtin
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

INFO=		bash

PORTDOCS=	CHANGES COMPAT FAQ INTRO NEWS POSIX RBASH README bash.html \
		bashref.html
DOCSDIR=	${PREFIX}/share/doc/bash
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--disable-rpath \
			--enable-disabled-builtins \
			--with-libiconv-prefix=${ICONV_PREFIX} \
			--without-bash-malloc

CONFLICTS+=	bash-[0-9]* bash-static-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC} || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ${NOSHARED:tl} != "no")
CONFIGURE_ARGS+=	--enable-static-link
LLD_UNSAFE=		yes
.else
CONFIGURE_ARGS+=	--disable-static-link
# Bash symbols must be exported in order to link runtime plugins, i.e.,
# "enable -f". (Plugins are not supported for bash-static.)
LDFLAGS+=		-Wl,-export-dynamic
.endif
STANDARD_PATH=		/sbin:/bin:/usr/sbin:/usr/bin
CPPFLAGS+=		-DDEFAULT_PATH_VALUE='\"${STANDARD_PATH}:${LOCALBASE}/sbin:${LOCALBASE}/bin\"' \
			-DSTANDARD_UTILS_PATH='\"${STANDARD_PATH}\"'

post-patch:
# Ensure y.tab.c is regenerated
	${TOUCH} ${WRKSRC}/parse.y
	${RM} ${WRKSRC}/y.tab.c
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/bash.1
.if ${PORT_OPTIONS:MSYSLOG}
	@${REINPLACE_CMD} \
	    -e "s|/\*.*#define SYSLOG_HISTORY .*\*/|#define SYSLOG_HISTORY|g" \
	    -e "s|/\*.*#define SYSLOG_SHOPT .*\*/|#define SYSLOG_SHOPT 1|g" \
	    ${WRKSRC}/config-top.h
.endif

post-patch-SYSBASHRC-on:
	@${REINPLACE_CMD} \
		-e "s|.*\(#define SYS_BASH.*\)\(/etc/.*\"\).*|\1${PREFIX}\2|" \
		${WRKSRC}/config-top.h

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|"

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

post-install:
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/rbash
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/bash
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${STAGEDIR}${DOCSDIR}
	for d in ${PORTDOCS:NFAQ:NINTRO:N*html}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${STAGEDIR}${DOCSDIR}; \
	done

regress: build
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

.include <bsd.port.mk>
