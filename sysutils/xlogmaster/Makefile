# New ports collection makefile for:	xlogmaster
# Version required:	1.6.0
# Date created:		1 August 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $Id: Makefile,v 1.9 1999/01/27 07:41:28 fenner Exp $
#

DISTNAME=	xlogmaster-1.6.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sunsite.doc.ic.ac.uk/packages/gnu/\
		${MASTER_SITE_GNU}\
		http://www.fusebox.hanse.de/xlogmaster/development/\
		http://porter.desy.de/~greve/xlogmaster/development/
MASTER_SITE_SUBDIR=	xlogmaster

MAINTAINER=	aw1@stade.co.uk

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

NO_PACKAGE=	ignores CFLAGS
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CXXFLAGS="${CFLAGS}" GTK_CONFIG="${X11BASE}/bin/gtk12-config"
USE_XLIB=	yes
USE_GMAKE=	yes

MAN1=		xlogmaster.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/xlogmaster.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${FILESDIR}/xlogmasterrc ${PREFIX}/etc/xlogmaster

.include <bsd.port.mk>
