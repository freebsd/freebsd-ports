# New ports collection makefile for:	PARI
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	pari
PORTVERSION=	2.1.6
CATEGORIES=	math
MASTER_SITES= http://pari.math.u-bordeaux.fr/pub/pari/unix/

MAINTAINER=	yoshiaki@kt.rim.or.jp
COMMENT=	Mathmatics library and advanced calculator package

EXTRACT_SUFX=   .tgz
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share
# build is broken on some locales
CONFIGURE_ENV=	LANG=C
MAKE_ENV=	LANG=C

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ARGS=	gp

MAN1=		gp.1 gphelp.1 tex2mail.1
MLINKS=		gp.1 pari.1

HAVE_EMACS!=	which emacs || echo nope
.if ${HAVE_EMACS} != "nope"
PLIST=		${PKGDIR}/pkg-plist.emacs
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
USE_GCC=    3.2
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on sparc64 or ia64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|"${CFLAGS}"|' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
