# New ports collection makefile for:	cvsup
# Version required:	13.4
# Date created:		7 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.9 1996/10/22 03:12:33 jdp Exp $
#

DISTNAME=	cvsup-13.4
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3\\.4\\.:${PORTSDIR}/lang/modula-3-lib

MAKE_ENV=	M3FLAGS=-DDYNAMIC

.include <bsd.port.mk>
