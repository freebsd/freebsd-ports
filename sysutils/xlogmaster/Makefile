# New ports collection makefile for:	xlogmaster
# Date created:		1 August 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xlogmaster
PORTVERSION=	1.6.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xlogmaster

MAINTAINER=	aw1@stade.co.uk

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

MAN1=		xlogmaster.1

post-install:
	@install-info ${PREFIX}/info/xlogmaster.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${FILESDIR}/xlogmasterrc ${PREFIX}/etc/xlogmaster

.include <bsd.port.mk>
