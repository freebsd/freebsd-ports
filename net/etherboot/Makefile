# New ports collection makefile for:   etherboot
# Date created:        16 April 1999
# Whom:                Doug Ambrisko <ambrisko@whistle.com>
#
# $FreeBSD$
#

PORTNAME=	etherboot
PORTVERSION=	5.2.4
PORTREVISION=	1
CATEGORIES=	net
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	${PORTNAME}
#use development sources for now instead of standard ftp site.
MASTER_SITES=	http://etherboot.sourceforge.net/

MAINTAINER=	ambrisko@freebsd.org
COMMENT=	Network boot of FreeBSD a.out/ELF kernels. Replaces/improves netboot.

NO_PACKAGE=	lots of configuration necessary
USE_BZIP2=	1
USE_GMAKE=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_PERL5_BUILD=yes
ONLY_FOR_ARCHS=	i386

do-install:
	@${ECHO} Refer ${DESCR} and ${WRKDIR}/${PKGNAME}/doc for how to
	@${ECHO} build and install the rom/floppy image.
	@exit 1

.include <bsd.port.mk>
