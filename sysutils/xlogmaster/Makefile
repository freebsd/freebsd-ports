# New ports collection makefile for:	xlogmaster
# Date created:		1 August 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xlogmaster
PORTVERSION= 	1.6.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sunsite.doc.ic.ac.uk/packages/gnu/\
		${MASTER_SITE_GNU}\
		http://www.fusebox.hanse.de/xlogmaster/development/\
		http://porter.desy.de/~greve/xlogmaster/development/
MASTER_SITE_SUBDIR=	xlogmaster

MAINTAINER=	aw1@stade.co.uk

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

NO_PACKAGE=	ignores CFLAGS
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
USE_XLIB=	yes
USE_GMAKE=	yes

MAN1=		xlogmaster.1

post-install:
	@install-info ${PREFIX}/info/xlogmaster.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${FILESDIR}/xlogmasterrc ${PREFIX}/etc/xlogmaster

.include <bsd.port.mk>
