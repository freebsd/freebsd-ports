# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.5.7
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/${PORTVERSION:R}.x/ \
		ftp://ftp.planetmirror.com/pub/lyx/stable/${PORTVERSION:R}.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/${PORTVERSION:R}.x/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/${PORTVERSION:R}.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/${PORTVERSION:R}.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/${PORTVERSION:R}.x/ \
		ftp://ftp.chg.ru/pub/X11/lyx/stable/${PORTVERSION:R}.x/ \
		http://lyx.mirror.fr/stable/${PORTVERSION:R}.x/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG) (stable)

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/share/texmf/tex/latex/prettyref/prettyref.sty:${PORTSDIR}/print/latex-prettyref \
		${LOCALBASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf

OPTIONS=	ASPELL	"Utilize Aspell library"			on \
		AIKSAUR	"Build Aiksaurus support (English thesaurus)"	on \
		NLS	"Native language support"			on

CONFLICTS=	lyx-1.4.*

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib moc_build uic_build
USE_GNOME=	gnometarget
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-frontend=qt4 \
		--without-included-boost \
		--without-included-gettext \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-extra-prefix=${LOCALBASE}
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
#ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

MAN1=		lyx.1 tex2lyx.1 lyxclient.1

LATEST_LINK=	lyx15

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_AIKSAUR)
LIB_DEPENDS+=	Aiksaurus:${PORTSDIR}/textproc/aiksaurus
.else
CONFIGURE_ARGS+=	--without-aiksaurus
.endif

.if defined(WITHOUT_ASPELL)
CONFIGURE_ARGS+=	--without-aspell --without-pspell
.else
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|boost/regex\.hpp|boost/cregex.hpp|' \
		${WRKSRC}/src/support/filetools.cpp

check test:
	# Running vendor's self-tests (currently known to fail):
	${GMAKE} -C ${WRKSRC} check

post-install:
	${LN} -sf ${DATADIR}/images/lyx.xpm ${PREFIX}/share/pixmaps/lyx.xpm
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lyx.desktop \
		${PREFIX}/share/applications

.include <bsd.port.post.mk>
