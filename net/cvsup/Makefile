# New ports collection makefile for:	cvsup
# Version required:	13.4
# Date created:		7 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.6 1996/09/13 00:13:17 jdp Exp $
#

DISTNAME=	cvsup-13.4
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

LIB_DEPENDS=	m3\\.3\\.:${PORTSDIR}/lang/modula-3

MAKE_ENV=	M3FLAGS=-DDYNAMIC

.include <bsd.port.mk>
