# New ports collection makefile for:	CJK-LyX
# Date created:		2 Jul 2000
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.3.4.1
CATEGORIES=	print
MASTER_SITES=	ftp://cellular.phys.pusan.ac.kr/CJK-LyX/qt/
PKGNAMEPREFIX=	cjk-
DISTNAME=	CJK-LyX-qt-${PORTVERSION:R}-${PORTVERSION:E}.src

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX, with CJK support

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX \
		makepsres:${X_CLIENTS_PORT}
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/CJK-LyX-qt-${PORTVERSION:R}

CONFLICTS=	lyx-*

USE_QT_VER=	3
USE_GNOME=	gnometarget lthack
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--with-frontend=qt \
		--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 reLyX.1

CFLAGS+=	-DI18N

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

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
