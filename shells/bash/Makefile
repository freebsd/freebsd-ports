# Please keep the commented variables for now, as we will need them once
# the first patchset is released

PORTNAME=		bash
#PATCHLEVEL=		0
#PORTVERSION=		5.3.${PATCHLEVEL:S/^0//g}
PORTVERSION=		5.3
CATEGORIES=		shells
MASTER_SITES=		GNU
#DISTNAME=		${PORTNAME}-${PORTVERSION:R}
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

#PATCH_SITES=		GNU/${PORTNAME}/${DISTNAME}-patches/
#PATCHFILES!=		/usr/bin/jot -s " " -w \
#			${PORTNAME}${PORTVERSION:R:S/.//g}-%03d \
#			${PATCHLEVEL} 1 ${PATCHLEVEL}

MAINTAINER=		ehaupt@FreeBSD.org
COMMENT=		GNU Project's Bourne Again SHell
WWW=			https://www.gnu.org/software/bash/

LICENSE=		GPLv3+
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			bison cpe iconv localbase pathfix
CPE_VENDOR=		gnu
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins \
			--with-libiconv-prefix=${ICONV_PREFIX}

MAKE_ARGS+=		TERMCAP_LIB=-ltinfow

INFO=			bash
PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH README \
			bash.html bashref.html

OPTIONS_DEFINE=		FDESCFS HELP NLS STATIC SYSBASHRC \
			SYSLOG DOCS
OPTIONS_DEFAULT=	HELP
OPTIONS_SUB=		yes

FDESCFS_DESC=		Enable use of /dev/fd
HELP_DESC=		Enable builtin help
SYSBASHRC_DESC=		Enable system-wide rc files

FDESCFS_CONFIGURE_ENV_OFF=	bash_cv_dev_fd=absent
FDESCFS_SUB_FILES=	pkg-message

HELP_CONFIGURE_ENABLE=	help-builtin
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

# Needs readline 8.3
#PORTS_READLINE_BUILD_DEPENDS=	readline>=8.2:devel/readline
#PORTS_READLINE_USES=	readline
#PORTS_READLINE_CONFIGURE_WITH=	installed-readline

.if empty(PKGNAMESUFFIX)
CONFLICTS+=	bash-static
.else
CONFLICTS+=	bash
.endif
CONFLICTS+=	bashc

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
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/doc/bash.1
.if ${PORT_OPTIONS:MSYSLOG}
	@${REINPLACE_CMD} \
	    -e "s|/\*.*#define SYSLOG_HISTORY .*\*/|#define SYSLOG_HISTORY|g" \
	    -e "s|/\*.*#define SYSLOG_SHOPT .*\*/|#define SYSLOG_SHOPT 1|g" \
	    ${WRKSRC}/config-top.h
.endif
	@${REINPLACE_CMD} -e "s|\(/etc/profile\)|${LOCALBASE}\1|" \
		${WRKSRC}/pathnames.h.in
	@${REINPLACE_CMD} -e "s|/etc/[iI]nputrc|${LOCALBASE}/etc/inputrc|g" \
		${WRKSRC}/doc/*.info ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.1 \
		${WRKSRC}/lib/readline/rlconf.h

post-patch-SYSBASHRC-on:
	@${REINPLACE_CMD} \
		-e "s|.*\(#define SYS_BASH.*\)\(/etc/.*\"\).*|\1${PREFIX}\2|" \
		${WRKSRC}/config-top.h

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
		| fgrep -v .sig | ${SORT} | ${TAIL}

.include <bsd.port.mk>
