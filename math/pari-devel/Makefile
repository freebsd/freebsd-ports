# New ports collection makefile for:	PARI-DEVEL
# Date created:		15 January 2001
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	pari
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}.${REV_VERSION}.b
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unstable/
DISTNAME=	pari-${MAJOR_VERSION}.${MINOR_VERSION}.${REV_VERSION}.beta

MAINTAINER=	yoshiaki@kt.rim.or.jp
COMMENT=	Mathmatics library and advanced calculator package

BROKEN=		Incorrect pkg-plist

CONFLICTS=	pari-2.1.*

NO_LATEST_LINK=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share

MAKE_ARGS=	gp
PLIST_SUB=	MAJOR_VERSION=${MAJOR_VERSION} MINOR_VERSION=${MINOR_VERSION} REV_VERSION=${REV_VERSION}

MAJOR_VERSION=	2
MINOR_VERSION=	2
REV_VERSION=	12

MAN1=		gp-2.2.1 gphelp.1 tex2mail.1
MLINKS=		gp-2.2.1 gp.1 gp.1 pari.1

.include <bsd.port.pre.mk>

HAVE_EMACS!=	${WHICH} emacs || ${ECHO} nope
.if ${HAVE_EMACS} != "nope"
PLIST=		${PKGDIR}/pkg-plist.emacs
.endif

.include <bsd.port.post.mk>
