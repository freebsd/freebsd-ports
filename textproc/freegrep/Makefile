# New ports collection makefile for:	grep
# Date created:		8 June 1999
# Whom:			Sheldon Hearn <sheldonh@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	freegrep
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.vocito.com/downloads/software/grep/ \
		ftp://ftp.vocito.com/pub/vocito.com/software/grep/
DISTNAME=	grep-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of grep(1) under a BSD-friendly license

LIB_DEPENDS=	iberty.1:${PORTSDIR}/devel/freelibiberty

CFLAGS:=	-I${LOCALBASE}/include/freelibiberty ${CFLAGS}

MAN1=		grep.1 egrep.1 fgrep.1 zgrep.1

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

.include <bsd.port.mk>
