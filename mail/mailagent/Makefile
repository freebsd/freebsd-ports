# New ports collection makefile for:	mailagent
# Version required:		3.0pl53+unofficial-patch
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1997/01/16 09:53:21 max Exp $
#

DISTNAME=	mailagent-3.0pl53
PKGNAME=	mailagent-3.0.53
CATEGORIES=	mail
MASTER_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/ \
		ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS

PATCHFILES=	mailagent-3.0pl53-unoff-patch.gz
PATCH_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5
BUILD_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_PACKAGE=	"Correct FQDN needs to be hardcoded"
WRKSRC=		${WRKDIR}/mailagent-3.0
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERLPATH}/perl' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' -Dmansrc='${PREFIX}/man/man1' \
			-Dnotifypatches='false'
MAKE_ENV=	PATH=${PERLPATH}:/bin:/sbin:/usr/bin:/usr/sbin
INSTALL_TARGET=	install install.man

MAN1=			edusers.1 mailagent.1 maildist.1  \
			maillist.1 mailpatch.1 package.1
# Note that mailhelp.1 is intentionally left uncompressed as it is referred
# from several other man pages with .so macro.
PERLPATH!=	dirname `which perl5.003`

pre-extract:
	@if [ `/bin/sh -c umask` != 022 ]; then \
	  echo "Please set umask to 022 before running make,"; \
	  echo "or mailagent will not build successfully."; \
	  false; fi

.include <bsd.port.mk>
