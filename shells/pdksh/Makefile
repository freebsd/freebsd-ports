# New ports collection makefile for:	pdksh
# Version required:	5.2.14
# Date created:		23 May 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	pdksh-5.2.14
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/ \
		http://gd.tuwien.ac.at/utils/shells/pdksh/ \
		ftp://ftp.lip6.fr/pub/unix/shells/pdksh/ \
		ftp://ftp.demon.net/pub/mirrors/pdksh/ \
		ftp://ftp.rge.com/pub/shells/pdksh/

MAINTAINER=	tg@FreeBSD.org

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	LDSTATIC=-static
MAN1=		ksh.1

.include <bsd.port.mk>
