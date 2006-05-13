# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://planetmirror.com/pub/lyx/stable/ \
		http://www-ftp.lip6.fr/ftp/pub/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost

CONFLICTS=	cjk-lyx-*

OPTIONS=	QT	"Use Qt (instead of XForms)"	${QT_PRESENT}	\
		ASPELL	"Utilize ASPELL library"	on	\
		ISPELL	"Depend on ISPELL as well"	off
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

#post-extract:
#	# Removing mention of the bundled boost
#	${REINPLACE_CMD} -e '/boost\/.*Makefile/d' ${WRKSRC}/configure.ac

post-patch:
	# Removing mention of the bundled boost
	${REINPLACE_CMD} -e 's, boost/[^ ]*Makefile,,g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,detail/nullstream,utils/nullstream,' \
	    ${WRKSRC}/src/pch.h ${WRKSRC}/src/support/pch.h \
	    ${WRKSRC}/src/support/debugstream.h
	${REINPLACE_CMD} -e 's,boost/regex\.hpp,boost/cregex.hpp,' \
	    ${WRKSRC}/src/support/filetools.C

post-configure:
	# Removing explicit linking with -lc
	${REINPLACE_CMD} -e 's,-lc ,,' ${WRKSRC}/*/Makefile

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/makepsres)
PLIST_SUB+=	PSRES=
.else
PLIST_SUB+=	PSRES='@comment '
.endif

.if defined(WITH_QT)
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
CONFIGURE_ARGS+=	--with-frontend=qt
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LDFLAGS=${PTHREAD_LIBS}
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/texcm-ttf/cmex10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf
.else
LIB_DEPENDS+=	forms:${PORTSDIR}/x11-toolkits/xforms
CONFIGURE_ARGS+=--with-frontend=xforms
USE_XPM=	yes
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

.if exists(${X11BASE}/lib/libqt-mt.prl)
QT_PRESENT=	on
.else
QT_PRESENT=	off
.endif

.if ${OSVERSION} < 500035
CFLAGS+=	-Wno-non-template-friend -ftemplate-depth-30
.endif

.include <bsd.port.post.mk>
