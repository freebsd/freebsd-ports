# New ports collection makefile for:	CJK-LyX
# Date created:		2 Jul 2000
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.1.5.2
CATEGORIES=	print
MASTER_SITES=	ftp://stone.phys.pusan.ac.kr/pub/CJK-LyX/
PKGNAMEPREFIX=	cjk-
DISTNAME=	CJK-LyX-1.1.5fix2-src

MAINTAINER=	cjh@FreeBSD.org

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif
LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_XPM=	yes
USE_NEWGCC=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-extra-lib="${X11BASE}/lib ${LOCALBASE}/lib" \
		--with-extra-inc="${X11BASE}/include ${LOCALBASE}/include"
MAKE_ENV+=	INTLLIBS="-L${LOCALBASE}/lib -lintl"
MAN1=		lyx.1 reLyX.1
WRKSRC=		${WRKDIR}/CJK-LyX-1.1.5fix2

.if !defined(WITH_ISPELL)
pre-fetch:
	@${ECHO_MSG} "If you want this port built with spell checker support, use"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

post-patch:
	(cd ${WRKSRC}; ${TOUCH} Makefile.in */Makefile.in src/config.h.in)

.include <bsd.port.mk>
