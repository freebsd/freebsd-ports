# New ports collection makefile for:	PARI
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	pari
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/ \
		http://www.gn-50uma.de/ftp/pari-2.1/

MAINTAINER=	yoshiaki@kt.rim.or.jp
COMMENT=	Mathmatics library and advanced calculator package

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

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|"${CFLAGS}"|' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
