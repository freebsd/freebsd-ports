# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.5.5
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://ftp.planetmirror.com/pub/lyx/stable/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/ \
		ftp://ftp.chg.ru/pub/X11/lyx/stable/ \
		http://lyx.mirror.fr/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG) (stable)

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/share/texmf/tex/latex/prettyref/prettyref.sty:${PORTSDIR}/print/latex-prettyref \
		${LOCALBASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost

LATEST_LINK=	lyx15
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LDFLAGS=${PTHREAD_LIBS}

OPTIONS=	ASPELL	"Utilize ASPELL library"	on	\
		AIKSAUR	"Build Aiksaurus support (English thesaurus)"	on	\
		NLS     "Native language support"	On

ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`
USE_BZIP2=	yes
USE_GNOME=	gnometarget lthack
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib moc_build uic_build

CONFLICTS=	lyx-1.4.*

EXTRACT_AFTER_ARGS=| ${TAR} -xf - --exclude ${PORTNAME}-${PORTVERSION}/intl/*.[ch]	\
	--exclude ${PORTNAME}-${PORTVERSION}/boost --exclude ${PORTNAME}-${PORTVERSION}/intl
CONFIGURE_ARGS=	--with-frontend=qt4 \
		--without-included-boost \
		--without-included-gettext \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-extra-prefix=${LOCALBASE}

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 tex2lyx.1 lyxclient.1

post-patch:
	# Removing mention of the bundled boost
	${REINPLACE_CMD} -e 's, boost/[^ ]*Makefile,,g' -e 's, intl/Makefile,,g'	\
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's, intl , ,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,detail/nullstream,utils/nullstream,' \
	    ${WRKSRC}/src/pch.h ${WRKSRC}/src/support/pch.h \
	    ${WRKSRC}/src/support/debugstream.h
	${REINPLACE_CMD} -e 's,boost/regex\.hpp,boost/cregex.hpp,' \
	    ${WRKSRC}/src/support/filetools.cpp

pre-configure:
	# If the installed Boost is 1.34 or later, we must compile
	# with exceptions enabled:
	${AWK} '/#define BOOST_VERSION / {exit($$NF >= 103400)}'	\
		${LOCALBASE}/include/boost/version.hpp || \
	${REINPLACE_CMD} -e 's,\(AM_CXXFLAGS="\)-fno-exceptions,\1,' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	# Removing explicit linking with -lc
	${REINPLACE_CMD} -e 's,-lc ,,' ${WRKSRC}/*/Makefile

check test:
	# Running vendor's self-tests (currently known to fail):
	${GMAKE} -C ${WRKSRC} check

post-install:
	${LN} -sf ${DATADIR}/images/lyx.xpm ${PREFIX}/share/pixmaps/lyx.xpm
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lyx.desktop \
		${PREFIX}/share/applications

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/makepsres)
PLIST_SUB+=	PSRES=
.else
PLIST_SUB+=	PSRES='@comment '
.endif

.if !defined(WITHOUT_AIKSAUR)
LIB_DEPENDS+=	Aiksaurus:${PORTSDIR}/textproc/aiksaurus
.else
CONFIGURE_ARGS+=--without-aiksaurus
.endif

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=--without-aspell --without-pspell
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# includes of qt4 must be found earlier than those of qt3
CONFIGURE_ENV+=	QT4_CORE_CFLAGS="-DQT_SHARED -I${QT_INCDIR}/QtCore \
		-I${QT_INCDIR}" \
	QT4_FRONTEND_CFLAGS="-DQT_SHARED -I${QT_INCDIR}/QtCore  \
		-I${QT_INCDIR}/QtGui -I${QT_INCDIR}"

.include <bsd.port.post.mk>
