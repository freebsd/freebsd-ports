# New ports collection makefile for:	cvsup
# Version required:	13.3
# Date created:		7 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.3 1996/08/23 20:51:19 jdp Exp $
#

DISTNAME=	cvsup-13.3
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

LIB_DEPENDS=	m3\\.354\\.:${PORTSDIR}/lang/modula-3

MAKE_ENV=	M3FLAGS=-DDYNAMIC

.include <bsd.port.mk>
