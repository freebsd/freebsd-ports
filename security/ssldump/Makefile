# New ports collection makefile for:	ssldump
# Date created:		07 Jun 2001
# Whom:			Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	ssldump
PORTVERSION=	0.9b1.p1
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/
DISTNAME=	ssldump-0.9b1
DIST_SUBDIR=	ssldump

PATCH_SITES=	http://www.rtfm.com/ssldump/
PATCHFILES=	patch1

MAINTAINER=	tacho@daemonz.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-openssl=/usr

MAN1=		ssldump.1

.include <bsd.port.mk>
