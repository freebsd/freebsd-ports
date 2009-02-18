# New ports collection makefile for:	pftabled
# Date created:		2006-11-21
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	pftabled
PORTVERSION=	1.06
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	chifeng@gmail.com
COMMENT=	The pftabled is a tool to manage your pf tables remotely

USE_RC_SUBR=	pftabled

MAN1=	pftabled.0

PLIST_FILES=	bin/pftabled-client sbin/pftabled

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
