# New ports collection makefile for:	grep
# Date created:		8 June 1999
# Whom:			Sheldon Hearn <sheldonh@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	freegrep
PORTVERSION= 	0.15
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.wam.umd.edu/pub/howardjp/software/grep/ \
		http://www.wam.umd.edu/~howardjp/software/grep/ \
		ftp://dragon.ham.muohio.edu/pub/howardjp/software/grep/
DISTNAME=	grep-${PORTVERSION}

MAINTAINER=	howardjp@wam.umd.edu

MAN1=		grep.1 egrep.1 fgrep.1 zgrep.1

LIB_DEPENDS=	iberty.1:${PORTSDIR}/devel/freelibiberty

post-extract:
	@(cd ${WRKSRC}; rm -f .depend)

.include <bsd.port.mk>
