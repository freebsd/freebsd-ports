# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=		bash
PATCHLEVEL=		7
PORTVERSION=		4.4.${PATCHLEVEL:S/^0//g}
PORTREVISION?=		0
CATEGORIES=		shells
MASTER_SITES=		GNU/${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION:R}
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=		GNU/${PORTNAME}/${DISTNAME}-patches/
PATCHFILES!=		/usr/bin/jot -s " " -w \
			${PORTNAME}${PORTVERSION:R:S/.//g}-%03d \
			${PATCHLEVEL} 1 ${PATCHLEVEL}

MAINTAINER=		ehaupt@FreeBSD.org
COMMENT=		GNU Project's Bourne Again SHell

LICENSE=		GPLv3

OPTIONS_DEFINE=		COLONBREAKSWORDS HELP NLS STATIC SYSLOG DOCS
COLONBREAKSWORDS_DESC=	Colons break words
HELP_DESC=		Enable builtin help

OPTIONS_DEFAULT=	COLONBREAKSWORDS HELP

USES=			bison cpe iconv makeinfo pathfix
GNU_CONFIGURE=		yes
OPTIONS_SUB=		yes
CPE_VENDOR=		gnu

COLONBREAKSWORDS_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-colonbreakswords

HELP_CONFIGURE_ENABLE=	help-builtin
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

INFO=			bash

PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH README \
			bash.html bashref.html

CONFIGURE_ARGS+=	--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins \
			--with-libiconv-prefix=${ICONV_PREFIX}

.if empty(PKGNAMESUFFIX)
CONFLICTS+=		bash-static-[0-9]*
.else
CONFLICTS+=		bash-[0-9]*
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC} || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ${NOSHARED:tl} != "no")
CONFIGURE_ARGS+=	--enable-static-link
.else
CONFIGURE_ARGS+=	--disable-static-link
# Bash symbols must be exported in order to link runtime plugins, i.e.,
# "enable -f". (Plugins are not supported for bash-static.)
CFLAGS+=		-Wl,-export-dynamic
.endif

post-patch:
# Ensure y.tab.c is regenerated
	${TOUCH} ${WRKSRC}/parse.y
	${RM} ${WRKSRC}/y.tab.c
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/bash.1
.if ${PORT_OPTIONS:MSYSLOG}
	@${REINPLACE_CMD} \
	    -e "s|/\*.*#define SYSLOG_HISTORY .*\*/|#define SYSLOG_HISTORY|g" \
	    ${WRKSRC}/config-top.h
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|"

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

post-install:
	${LN} -sf bash ${STAGEDIR}${PREFIX}/bin/rbash
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${STAGEDIR}${DOCSDIR}
	for d in ${PORTDOCS:NFAQ:NINTRO:N*html}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${STAGEDIR}${DOCSDIR}; \
	done

regress: build
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

ckp:
	${MAKE} -DPATCH_DEBUG clean patch

# requires ftp/ncftp3
cklatest:
	@${ECHO} -n "Currently at: "
	@${MAKE} -V PATCHLEVEL
	-ncftpls \
		${PATCH_SITES:Mftp*:Ox:[1]} \
		| fgrep -v .sig | ${TAIL}

.include <bsd.port.mk>
