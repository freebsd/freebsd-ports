# New ports collection makefile for:	mailagent
# Version required:		3.0pl56
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.18 1997/06/24 20:59:30 max Exp $
#

DISTNAME=		mailagent-3.0@56
PKGNAME=		mailagent-3.0.56
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/RAM/

MAINTAINER=	max@FreeBSD.ORG

USE_PERL5=	yes
NO_PACKAGE=	"Correct FQDN needs to be hardcoded"
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERLPATH}/perl' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' -Dmansrc='${PREFIX}/man/man1' \
			-Dnotifypatches='false'
MAKE_ENV=	PATH=${PERLPATH}:${PATH}
INSTALL_TARGET=	install install.man

# Note that mailhelp.1 is intentionally left uncompressed as it is referred
# from several other man pages with .so macro.
MAN1=			edusers.1 mailagent.1 maildist.1  \
			maillist.1 mailpatch.1 package.1
PERLPATH?=		${PREFIX}/bin

pre-extract:
	@if [ `${SH} -c umask` != 0022 ]; then \
	  echo "Please set umask to 022 before running make,"; \
	  echo "or mailagent will not build successfully."; \
	  false; fi

.include <bsd.port.mk>
