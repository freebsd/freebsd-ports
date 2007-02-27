# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	print chinese japanese korean
MASTER_SITES=	ftp://cellular.phys.pusan.ac.kr/CJK-LyX/qt/ \
		ftp://ftp.u-aizu.ac.jp/pub/tex/cjk-lyx/qt/ \
		http://www.otaru-uc.ac.jp/~yokota/comp/CJK-LyX/:JPN
PKGNAMEPREFIX=	cjk-
DISTNAME=	CJK-LyX-qt-${PORTVERSION}
DISTFILES=	${DISTNAME}-1.src${EXTRACT_SUFX} \
		lyx-platex-${PORTVERSION}.tar.gz:JPN \
		lyx-1.4_2.mo:JPN
DIST_SUBDIR=	CJK-LyX
EXTRACT_ONLY=	${DISTNAME}-1.src${EXTRACT_SUFX} \
		lyx-platex-${PORTVERSION}.tar.gz

PATCH_SITES=	http://www.otaru-uc.ac.jp/~yokota/comp/CJK-LyX/
PATCHFILES=	patch-platex-${PORTVERSION}.diff

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost \
		qt-mt:${PORTSDIR}/x11-toolkits/qt33
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf

BROKEN=		Does not build

CONFLICTS=	lyx-*
OPTIONS=	ASPELL	"Utilize ASPELL library"	on \
		ISPELL	"Depend on ISPELL as well"	off
.if defined(LANG) && ${LANG:C/_.*//} == "ja"
OPTIONS+=	JATETEX "Use pLaTeX (Japanese LaTeX)" ON
.else
OPTIONS+=	JATETEX "Use pLaTeX (Japanese LaTeX)" OFF
.endif

ALL_TARGET=	all check
USE_GNOME=	gnometarget lthack
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
EXTRACT_AFTER_ARGS=| ${TAR} -xf - --exclude ${PORTNAME}-${PORTVERSION}/intl/*.[ch] --exclude ${PORTNAME}-${PORTVERSION}/boost
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--without-included-boost \
		--with-extra-inc="${LOCALBASE}/include" \
		--with-frontend=qt
CONFIGURE_ENV+=	LDFLAGS=${PTHREAD_LIBS}
CFLAGS=		${PTHREAD_CFLAGS}
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 tex2lyx.1 lyxclient.1

# Make uic stay off the lawn
MAKE_ENV=	TMPDIR=/tmp

post-patch:
	# Removing mention of the bundled boost
	${REINPLACE_CMD} -e 's, boost/[^ ]*Makefile,,g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,detail/nullstream,utils/nullstream,' \
	    ${WRKSRC}/src/pch.h ${WRKSRC}/src/support/pch.h \
	    ${WRKSRC}/src/support/debugstream.h
	${REINPLACE_CMD} -e 's,boost/regex\.hpp,boost/cregex.hpp,' \
	    ${WRKSRC}/src/support/filetools.C
	${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,'      \
	    ${WRKSRC}/src/support/tests/test_*

post-configure:
	# Removing explicit linking with -lc
	${REINPLACE_CMD} -e 's,-lc ,,' ${WRKSRC}/*/Makefile

post-build:
	@${ECHO_MSG}
	@${ECHO_MSG} "Fixing up the Japanese message file..."
	@${ECHO_MSG}
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/lyx-1.4_1.mo ${WRKSRC}/po/ja.gmo

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/makepsres)
PLIST_SUB+=	PSRES=
.else
PLIST_SUB+=	PSRES='@comment '
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

# Choose appropriate settings for each LaTeX
.if defined(WITH_JATETEX)
BUILD_DEPENDS+=	latex:${PORTSDIR}/japanese/teTeX
RUN_DEPENDS+=	latex:${PORTSDIR}/japanese/teTeX
.else
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.endif

.if ${OSVERSION} < 500035
CFLAGS+=	-Wno-non-template-friend -ftemplate-depth-30
.elif ${OSVERSION} >= 700007 && ${ARCH} == i386 && ${CXX} == c++
BROKEN=		C++ compiler seg-faults, try using a different one and report to ${MAINTAINER}
.endif

.include <bsd.port.post.mk>
