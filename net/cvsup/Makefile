# New ports collection makefile for:	cvsup
# Version required:	13.4
# Date created:		7 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.8 1996/10/20 14:26:24 wosch Exp $
#

DISTNAME=	cvsup-13.4
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

LIB_DEPENDS=	m3\\.3\\.:${PORTSDIR}/lang/modula-3

MAKE_ENV=	M3FLAGS=-DDYNAMIC

pre-fetch warning:
	@${ECHO} "WARNING  WARNING  WARNING  WARNING  WARNING  WARNING"
	@${ECHO} "CVSup depends on Modula-3, which requires > 30MB disk space."
	@${ECHO} "You don't need to install Modula-3 unless you want it for
	@${ECHO} "some other reason.  You can get static binaries of CVSup"
	@${ECHO} "from:"
	@${ECHO} ""
	@${ECHO} "	ftp://freefall.freebsd.org/pub/CVSup/"
	@${ECHO} ""

.include <bsd.port.mk>
