# New ports collection makefile for:	mailagent
# Version required:		3.0.44
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1996/11/02 20:24:00 max Exp $
#

DISTNAME=	mailagent-3.0pl44
PKGNAME=	mailagent-3.0.44
CATEGORIES=	mail
MASTER_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/ 

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5
BUILD_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

WRKSRC=		${WRKDIR}/mailagent-3.0

NO_PACKAGE=	"Correct FQDN needs to be hardcoded."
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-dres \
			-Dccflags='${CFLAGS} -D_HAVE_PARAM_H' \
			-Dperlpath='/usr/local/bin/perl' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' -Dmansrc='${PREFIX}/man/man1' \
			-Dnotifypatches='false'
INSTALL_TARGET=	install install.man

MANPAGES=			edusers.1 mailagent.1 maildist.1  \
				maillist.1 mailpatch.1 package.1
# Note that mailhelp.1 is intentionally left uncompressed as it is referred
# from several other man pages with .so macro.

post-install:
.for manpage in ${MANPAGES}
	${COMPRESS_MAN} ${PREFIX}/man/man1/${manpage}
.endfor

.include <bsd.port.mk>
