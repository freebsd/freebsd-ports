# New ports collection makefile for:	cvsup
# Version required:	13.4
# Date created:		7 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.7 1996/09/27 02:33:15 jdp Exp $
#

DISTNAME=	cvsup-13.4
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

LIB_DEPENDS=	m3\\.3\\.:${PORTSDIR}/lang/modula-3

MAKE_ENV=	M3FLAGS=-DDYNAMIC

pre-fetch warning:
	@${ECHO} "WARNING  WARNING  WARNING  WARNING  WARNING  WARNING"
	@${ECHO} "CVSup depend on Modula-3, which require > 30MB disk space."
	@${ECHO} "You don't need install Modula unless you want it for some"
	@${ECHO} "other reason. Get the static binary of cvsup on freefall in"
	@${ECHO} ""
	@${ECHO} "	ftp://freefall.freebsd.org/pub/CVSup/cvsup-bin-*"
	@${ECHO} ""
	@${ECHO} ""

.include <bsd.port.mk>
