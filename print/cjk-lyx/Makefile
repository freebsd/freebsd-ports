# New ports collection makefile for:	CJK-LyX
# Date created:		2 Jul 2000
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://stone.phys.pusan.ac.kr/pub/CJK-LyX/
PKGNAMEPREFIX=	cjk-
DISTNAME=	CJK-LyX-${PORTVERSION}-src

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX, with CJK support

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		forms.1:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/CJK-LyX-${PORTVERSION}

USE_XPM=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-DI18N"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-extra-lib="${LOCALBASE}/lib" \
		--with-extra-inc="${LOCALBASE}/include"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAN1=		lyx.1 reLyX.1

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell.15:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell \
			--with-pspell-lib="${LOCALBASE}/lib" \
			--with-pspell-include="${LOCALBASE}/include" 
.endif

.if defined(WITH_ISPELL)
RUN_DEPENDS+=   ispell:${PORTSDIR}/textproc/ispell
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

post-patch:
.for file in src/Makefile.am src/frontends/Makefile.am
	@${REINPLACE_CMD} -e 's|LIBS +=|LDFLAGS = @LDFLAGS@|g' ${WRKSRC}/${file}
.endfor
.for file in configure.in lib/reLyX/configure.in
	@${REINPLACE_CMD} -e 's|AC_CHECK_LIB(c,|AC_CHECK_FUNC(|g ; \
		 s|^INSTALL_SCRIPT=|#INSTALL_SCRIPT=|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
