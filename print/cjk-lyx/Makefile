# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	lyx
PORTVERSION=	1.4.4
PORTREVISION=	10
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

OPTIONS_DEFINE=	ASPELL ISPELL JATETEX
OPTIONS_DEFAULT=	ASPELL
OPTIONS_DEFAULT+=	JATETEX
JATETEX_DESC=	pLaTeX (Japanese LaTeX)

ALL_TARGET=	all check
MAKE_JOBS_UNSAFE=	yes
USE_GNOME=	lthack
USE_PERL5=	yes
USE_PYTHON=	yes
USES=		gettext gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include" \
		--with-frontend=qt \
		--program-prefix="${PKGNAMEPREFIX}"
LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}
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
.include <bsd.port.options.mk>

PLIST_SUB=	PKGNAMEPREFIX=${PKGNAMEPREFIX}

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.endif

.if ${PORT_OPTIONS:MISPELL}
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

# Choose appropriate settings for each LaTeX
.if ${PORT_OPTIONS:MJATETEX}
USE_TEX=	ptex
.else
USE_TEX=	latex
.endif

.include <bsd.port.mk>
