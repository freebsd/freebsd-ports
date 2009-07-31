# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.4.5.1
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/1.4.x/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/1.4.x/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/1.4.x/ \
		ftp://ftp.ntua.gr/pub/X11/LyX/stable/1.4.x/ \
		http://sunsite.icm.edu.pl/pub/unix/editors/lyx/stable/1.4.x/ \
		ftp://ftp.chg.ru/pub/X11/lyx/stable/1.4.x/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

OPTIONS=	QT	"Use Qt (instead of XForms)"	${QT_PRESENT}	\
		ASPELL	"Utilize ASPELL library"	on	\
		AIKSAUR	"Build Aiksaurus support (English thesaurus)"	on	\
		ISPELL	"Depend on ISPELL as well"	off
ALL_TARGET=	all check
USE_BZIP2=	yes
USE_GNOME=	gnometarget lthack
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
EXTRACT_AFTER_ARGS=| ${TAR} -xf - --exclude ${PORTNAME}-${PORTVERSION}/intl/*.[ch] --exclude ${PORTNAME}-${PORTVERSION}/boost
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--without-included-boost \
		--with-extra-inc="${LOCALBASE}/include"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 tex2lyx.1 lyxclient.1

post-patch:
	# Removing mention of the bundled boost
	${REINPLACE_CMD} -e 's, boost/[^ ]*Makefile,,g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,detail/nullstream,utils/nullstream,' \
	    ${WRKSRC}/src/pch.h ${WRKSRC}/src/support/pch.h \
	    ${WRKSRC}/src/support/debugstream.h
	${REINPLACE_CMD} -e 's,boost/regex\.hpp,boost/cregex.hpp,' \
	    ${WRKSRC}/src/support/filetools.C
	${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,'	\
	    ${WRKSRC}/src/support/tests/test_*

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

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/makepsres)
PLIST_SUB+=	PSRES=
.else
PLIST_SUB+=	PSRES='@comment '
.endif

.if defined(WITH_AIKSAUR)
LIB_DEPENDS+=	Aiksaurus:${PORTSDIR}/textproc/aiksaurus
.else
CONFIGURE_ARGS+=--without-aiksaurus
.endif

.if defined(WITH_QT)
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
CONFIGURE_ARGS+=	--with-frontend=qt
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LDFLAGS=${PTHREAD_LIBS}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf
.else
LIB_DEPENDS+=	forms:${PORTSDIR}/x11-toolkits/xforms
CONFIGURE_ARGS+=--with-frontend=xforms
USE_XORG=	x11
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=--without-aspell --without-pspell
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.else
CONFIGURE_ARGS+=--without-ispell
.endif

.if exists(${LOCALBASE}/lib/libqt-mt.prl)
QT_PRESENT=	on
.else
QT_PRESENT=	off
.endif

.if ${OSVERSION} >= 700007 && ${ARCH} == i386 && ${CXX} == c++
#BROKEN=		C++ compiler seg-faults, try using a different one and report to ${MAINTAINER}
.endif

.include <bsd.port.post.mk>
