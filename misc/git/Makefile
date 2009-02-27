# New ports collection makefile for:	git
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnuit
PORTVERSION=	4.9.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-transition
MAN1=		gitaction.1 gitdpkgname.1 gitfm.1 gitinternal.1 \
		gitkeys.1 gitmount.1 gitps.1 gitregrep.1 gitrfgrep.1 \
		gitrgrep.1 gitunpack.1 gitview.1 gitwipe.1

post-install:
	 ${RM} -f ${PREFIX}/man/man1/gitmkdirs.1
	 ${RM} -f ${PREFIX}/man/man1/gitwhich.1
	 ${RM} -f ${PREFIX}/man/man1/gitxgrep.1

.include <bsd.port.mk>
