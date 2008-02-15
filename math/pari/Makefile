# New ports collection makefile for:	PARI
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	pari
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}.${REV_VERSION}
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/
DISTNAME=	pari-${MAJOR_VERSION}.${MINOR_VERSION}.${REV_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematics library and advanced calculator package

USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share

MAKE_ARGS=	gp
PLIST_SUB=	MAJOR_VERSION=${MAJOR_VERSION} MINOR_VERSION=${MINOR_VERSION} REV_VERSION=${REV_VERSION}

MAJOR_VERSION=	2
MINOR_VERSION=	3
REV_VERSION=	3

MAN1=		gp.1 gphelp.1 gp-${MAJOR_VERSION}.${MINOR_VERSION}.1 tex2mail.1
MLINKS=		gp.1 pari.1

.include <bsd.port.pre.mk>

post-install:
	@if [ -L ${PREFIX}/man/man1/pari.1 ]; then \
		${RM} -f ${PREFIX}/man/man1/pari.1 ;\
	fi

HAVE_EMACS!=	${WHICH} emacs || ${ECHO} nope
HAVE_PERL!=	${WHICH} perl || ${ECHO} nope
.if ${HAVE_EMACS} != "nope"
.if ${HAVE_PERL} != "nope"
PLIST=		${PKGDIR}/pkg-plist.emacs.perl
.else
PLIST=		${PKGDIR}/pkg-plit.emacs.noperl
.endif
.else
.if ${HAVE_PERL} != "nope"
PLIST=		${PKGDIR}/pkg-plist.perl
.endif
.endif

.include <bsd.port.post.mk>
