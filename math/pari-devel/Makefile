# New ports collection makefile for:	PARI-DEVEL
# Date created:		15 January 2001
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	pari
PORTVERSION=	2.2.0.a
CATEGORIES=	math
MASTER_SITES=	ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.2/
DISTNAME=	pari-2.2.0.alpha

MAINTAINER=	yoshiaki@kt.rim.or.jp

ONLY_FOR_ARCHS=	i386

NO_LATEST_LINK=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share

USE_GMAKE=	yes
MAKE_ARGS=	gp

MAN1=		gp.1 gphelp.1 tex2mail.1
MLINKS=		gp.1 pari.1

.include <bsd.port.pre.mk>

HAVE_EMACS!=	${WHICH} emacs || ${ECHO} nope
.if ${HAVE_EMACS} != "nope"
PLIST=		${PKGDIR}/pkg-plist.emacs
.endif

.include <bsd.port.post.mk>
