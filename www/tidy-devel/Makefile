# New ports collection makefile for:	tidy
# Date created:		27 Oct 1998
# Whom:			Abel Chow <achow@transoft.net>
#
# $FreeBSD$
#

PORTNAME?=	tidy
PORTVERSION=	050324
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/%SUBDIR%/	\
		http://tidy.sourceforge.net/docs/:docs
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX?=	-devel
DISTNAME=	tidy_src
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	thierry@FreeBSD.org
COMMENT?=	Utility to clean up and pretty print HTML/XHTML/XML

WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(WITH_SHLIB)
USE_GMAKE=	yes
PLIST_SUB=	SHLIB="@comment "
.else
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS+=	-a -c --foreign
USE_AUTOCONF_VER=	213
CONFIGURE_TARGET=	 --target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
PLIST_SUB=	SHLIB=""
.endif

DESCR=		${.CURDIR}/pkg-descr

BIN2STRIP=	tidy tab2space

.if !defined(WITH_SHLIB)
MAN1=		tidy.1
.endif

.if !defined(NOPORTDOCS)
DOCVER=		050310
DISTFILES+=	tidy_docs_${DOCVER}${EXTRACT_SUFX}:docs
DOCFILES=	Overview.html faq.html grid.gif pending.html	\
		quickref.html release-notes.html tidy.css tidy.gif
.endif

post-patch:
.if !defined(WITH_SHLIB)
	@${CP} ${WRKSRC}/build/gmake/Makefile ${WRKSRC}
.else
	@${CP} -R -f ${WRKSRC}/build/gnuauto/* ${WRKSRC}
.endif

patch-autotools:
.if defined(WITH_SHLIB)
	@(cd ${WRKSRC}				\
	&& ${LIBTOOLIZE} --force --copy		\
	&& ${ACLOCAL})
	@(cd ${PATCH_WRKSRC};			\
	for ltf in ${LIBTOOLFILES}; do		\
		${CP} $$ltf $$ltf.tmp;	\
		${SED} -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
			-e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			$$ltf.tmp > $$ltf;	\
	 done);
.endif

pre-install:
	@if [ -f ${LOCALBASE}/bin/tidy ]; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Conflict: another tidy has been found; please deinstall it." ; \
		${ECHO_MSG} "(`pkg_info -W ${LOCALBASE}/bin/tidy`)" ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi

post-install:
.for pgm in ${BIN2STRIP}
	@${STRIP_CMD} ${PREFIX}/bin/${pgm}
.endfor
.if defined(WITH_SHLIB)
	@${STRIP_CMD} ${PREFIX}/lib/libtidy-0.99.so.0
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}/api
	@${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/htmldoc/|} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/htmldoc/api/* ${DOCSDIR}/api
	@${ECHO_MSG} "===>   Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
