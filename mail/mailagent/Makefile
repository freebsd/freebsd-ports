# New ports collection makefile for:	mailagent
# Version required:		3.0pl63
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.23 1998/04/04 09:08:00 max Exp $
#

DISTNAME=		mailagent-3.0@63
PKGNAME=		mailagent-3.0.63
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/RAM

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
	@if [ `id -u` = 0 ]; then \
	  echo "Do not build mailagent as root or it won't pass the sanity tests."; \
	  false; fi

post-install:
	@${MKDIR} ${PREFIX}/share/examples/mailagent/agent
	@${MKDIR} ${PREFIX}/share/examples/mailagent/misc
	${INSTALL_DATA} ${WRKSRC}/agent/examples/* ${PREFIX}/share/examples/mailagent/agent
	${CP} -pR ${WRKSRC}/misc/* ${PREFIX}/share/examples/mailagent/misc

.include <bsd.port.mk>
