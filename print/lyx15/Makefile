# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.3.3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

USE_BZIP2=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	14
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 reLyX.1

.if defined(WITH_QT)
USE_QT_VER=	3
CONFIGURE_ARGS+=	--with-frontend=qt
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}
.else
LIB_DEPENDS+=	forms.1:${PORTSDIR}/x11-toolkits/xforms
USE_XPM=	yes
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell.15:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include"
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CFLAGS+=	-Wno-non-template-friend -ftemplate-depth-30
.endif

pre-everything::
.if !defined(WITH_QT)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to build with the Qt3 frontend,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_QT=yes\""
	@${ECHO_MSG}
.endif

.if !defined(WITH_ASPELL)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Aspell/Pspell support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_ASPELL=yes\""
	@${ECHO_MSG}
.endif

.if !defined(WITH_ISPELL)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Ispell support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_ISPELL=yes\""
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
