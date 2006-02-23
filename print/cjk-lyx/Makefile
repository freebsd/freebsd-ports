# New ports collection makefile for:	CJK-LyX
# Date created:		2 Jul 2000
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.3.5
CATEGORIES=	print chinese japanese korean
MASTER_SITES=	http://www.otaru-uc.ac.jp/~yokota/comp/CJK-LyX/ \
		http://www.otaru-uc.ac.jp/~yokota/comp/layouts/:JPN \
		ftp://cellular.phys.pusan.ac.kr/CJK-LyX/${FORM}/
PKGNAMEPREFIX=	cjk-
DISTNAME=	CJK-LyX-${FORM}-${PORTVERSION}-1.src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		lyx-platex-patch-${FORM}-${PORTVERSION}.tar.gz:JPN \
		lyx.mo:JPN
DIST_SUBDIR=	CJK-LyX
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		lyx-platex-patch-${FORM}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX, with CJK support

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		xvinfo:${X_CLIENTS_PORT}
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

CONFLICTS=	lyx-[0-9]*
WRKSRC=		${WRKDIR}/CJK-LyX-${FORM}-${PORTVERSION}
EXTRA_PATCHES=	${WRKDIR}/platex.patch
.if !defined(NOPORTDOCS)
MASTER_SITES+=	http://133.16.174.22/lyx/lyx-manual/:JADOC
JADOCVER=	1.3.3-1
JADOCNAME=	ja_LyX_Doc-${JADOCVER}.tar.gz
JADOCWRK=	1.3.3
DISTFILES+=	${JADOCNAME}:JADOC
EXTRACT_ONLY+=	${JADOCNAME}
.endif

USE_GNOME=	gnometarget lthack
USE_PERL5=	yes
USE_QT_VER=	3
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

OPTIONS=	QT "Compile with qt instead of xforms (recommended)" ON \
		ASPELL "Compile with aspell support" ON \
		ISPELL "Compile with ispell support" OFF
.if defined(LANG) && ${LANG:C/_.*//} == "ja"
OPTIONS+=	JATETEX "Set Japanese teTeX dependency (recommended to Japanese users)" ON
.else
OPTIONS+=	JATETEX "Set Japanese teTeX dependency (recommended to Japanese users)" OFF
.endif

.include <bsd.port.pre.mk>

# Choose an appropriate localized LaTeX as dependency
.if defined(WITH_JATETEX)
RUN_DEPENDS+=	latex:${PORTSDIR}/japanese/teTeX
.else
RUN_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.endif

CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 reLyX.1

CFLAGS+=	-DI18N
.if ${OSVERSION} < 500035
CFLAGS+=	-Wno-non-template-friend -ftemplate-depth-30
.endif

.if !defined(WITHOUT_QT)
FORM=		qt
CONFIGURE_ARGS+=	--with-frontend=qt
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf
PLIST_SUB+=	WITH_XFORMS="@comment "
.else
FORM=		xforms
LIB_DEPENDS+=	forms.1:${PORTSDIR}/x11-toolkits/xforms-i18n
USE_XPM=	yes
CONFIGURE_ARGS+=	--with-extra-inc="${X11BASE}/include/X11"
PLIST_SUB+=	WITH_XFORMS=""
.endif

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

post-extract::
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting Japanese documentations to the source tree..."
	@${ECHO_MSG}
	@${MV} ${WRKDIR}/${JADOCWRK}/* ${WRKSRC}/lib/doc
	@${RMDIR} ${WRKDIR}/${JADOCWRK}
.endif

post-build::
	@${ECHO_MSG}
	@${ECHO_MSG} "Fixing up the Japanese message file..."
	@${ECHO_MSG}
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/lyx.mo ${WRKSRC}/po/ja.gmo

.include <bsd.port.post.mk>
