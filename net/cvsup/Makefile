# New ports collection makefile for:	cvsup
# Version required:	13.2
# Date created:		7 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1996/08/08 09:25:54 asami Exp $
#

DISTNAME=	cvsup-13.2
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

LIB_DEPENDS=	m3\\.353\\.:${PORTSDIR}/lang/modula-3

MAKE_ENV=	M3FLAGS=-DDYNAMIC

.include <bsd.port.mk>
