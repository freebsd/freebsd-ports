# New ports collection makefile for:	upclient
# Version required:	3.04
# Date created:		20 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

DISTNAME=	upclient-3.04
CATEGORIES=	misc
MASTER_SITES=	ftp://uptime.hexon.cx/pub/ \
		http://uptime.hexon.cx/download/

MAINTAINER=	kbyanc@posi.net

ALL_TARGET=	bsd
INSTALL_TARGET=	bsd install CP=$(CP)

post-install:
	${CAT} ${PKGMESSAGE} | ${SED} 's:/usr/local:${PREFIX}:g'

.include <bsd.port.mk>
