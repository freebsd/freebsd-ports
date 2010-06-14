# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	${MAJOR_VERSION}.6.1
CATEGORIES=	print editors
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/${MAJOR_VERSION}.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/${MAJOR_VERSION}.x/ \
		ftp://ftp.chg.ru/pub/X11/lyx/stable/${MAJOR_VERSION}.x/

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG) (stable)

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs

CONFLICTS=	lyx-1.4*
MAJOR_VERSION=	1.6

USE_BZIP=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build uic_build rcc_build
USE_PYTHON=	yes
USE_PERL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-frontend=qt4 \
		--without-included-boost \
		--without-included-gettext \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-extra-prefix=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

MAN1=		lyx.1 lyxclient.1 tex2lyx.1

OPTIONS=	ASPELL	"Use Aspell library"	on \
		AIKSAUR	"Build Aiksaurus support (English thesaurus)"	on \
		NLS	"Native language support"	on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_AIKSAUR)
LIB_DEPENDS+=	Aiksaurus:${PORTSDIR}/textproc/aiksaurus
.else
CONFIGURE_ARGS+=	--without-aiksaurus
.endif

.if !defined(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--without-aspell --without-pspell
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
