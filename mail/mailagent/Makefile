# New ports collection makefile for:	mailagent
# Version required:		3.0pl56
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.15 1997/05/24 13:17:10 jfitz Exp $
#

DISTNAME=		mailagent-3.0@56
PKGNAME=		mailagent-3.0.56
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/RAM/

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5
BUILD_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

NO_PACKAGE=	"Correct FQDN needs to be hardcoded"
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
PERLPATH!=	dirname `which perl5.004`

pre-extract:
	@if [ `/bin/sh -c umask` != 0022 ]; then \
	  echo "Please set umask to 022 before running make,"; \
	  echo "or mailagent will not build successfully."; \
	  false; fi

.include <bsd.port.mk>
