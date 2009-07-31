# New ports collection makefile for:	cjk-lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.4.4
PORTREVISION=	4
CATEGORIES=	print chinese japanese korean
MASTER_SITES=	ftp://cellular.phys.pusan.ac.kr/CJK-LyX/qt/ \
		ftp://ftp.u-aizu.ac.jp/pub/tex/cjk-lyx/qt/ \
		http://www.otaru-uc.ac.jp/~yokota/comp/CJK-LyX/:JPN
PKGNAMEPREFIX=	cjk-
DISTNAME=	CJK-LyX-qt-${PORTVERSION}
DISTFILES=	${DISTNAME}-1.src${EXTRACT_SUFX} \
		lyx-platex-${PORTVERSION}.tar.gz:JPN
DIST_SUBDIR=	CJK-LyX
EXTRACT_ONLY=	${DISTNAME}-1.src${EXTRACT_SUFX} \
		lyx-platex-${PORTVERSION}.tar.gz

PATCH_SITES=	http://www.otaru-uc.ac.jp/~yokota/comp/CJK-LyX/
PATCHFILES=	patch-platex-${PORTVERSION}.diff

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs \
		qt-mt:${PORTSDIR}/x11-toolkits/qt33
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf

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
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include" \
		--with-frontend=qt \
		--program-prefix="${PKGNAMEPREFIX}"
CONFIGURE_ENV+=	LDFLAGS=${PTHREAD_LIBS}
CFLAGS=		${PTHREAD_CFLAGS}
MAN1=		${PKGNAMEPREFIX}lyx.1 ${PKGNAMEPREFIX}tex2lyx.1 ${PKGNAMEPREFIX}lyxclient.1

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

# Make uic stay off the lawn
MAKE_ENV=	TMPDIR=/tmp

post-extract:
	${MV} ${WRKSRC}/po/lyx.pot ${WRKSRC}/po/${PKGNAMEPREFIX}lyx.pot

post-configure:
	# Removing explicit linking with -lc
	${REINPLACE_CMD} -e 's,-lc ,,' ${WRKSRC}/*/Makefile

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Type \"${PKGNAMEPREFIX}lyx\" to execute the program."
	@${ECHO_MSG}
	@${ECHO_MSG} "User setting folder will be created under ~/.${PKGNAMEPREFIX}lyx when ${PKGNAMEPREFIX}lyx is run for the first time."
	@${ECHO_MSG}
.include <bsd.port.pre.mk>

PLIST_SUB=	PKGNAMEPREFIX=${PKGNAMEPREFIX}

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

.include <bsd.port.post.mk>
