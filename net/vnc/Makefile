# New ports collection makefile for:	vnc
# Version required:     3.3.2r3
# Date created:		24 February 1998
# Whom:			msmith
#
# $Id: Makefile,v 1.7 1998/11/21 07:27:39 steve Exp $
#

DISTNAME=       	vnc-3.3.2r3_unixsrc
PKGNAME=        	vnc-3.3.2r3
CATEGORIES=		net
MASTER_SITES=   	http://www.orl.co.uk/vnc/dist/
DISTFILES=		vnc-3.3.2r3_unixsrc.tgz \
			vnc-3.3.2_doc.tgz

MAINTAINER=	 	bmah@ca.sandia.gov

USE_PERL5=		YES

EXTRACT_ONLY=		vnc-3.3.2r3_unixsrc.tgz
IGNOREFILES=		${DISTFILES}

NO_WRKSUBDIR=		YES

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

ALL_TARGET=    		World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKDIR}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKDIR}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED}  -e s%/usr/local/vnc/classes%${PREFIX}/share/vnc/classes% \
		-e s%^\#!/usr/bin/perl%\#!${PERL}% \
		< ${WRKDIR}/vncserver \
		> ${WRKDIR}/vncserver.local
	${INSTALL_SCRIPT} ${WRKDIR}/vncserver.local ${PREFIX}/bin/vncserver
# The documentation comes with bogus ownerships; this is a little leaky security-wise
	${MKDIR} ${PREFIX}/share/doc/vnc
	tar -C ${PREFIX}/share/doc/vnc -xzf ${DISTDIR}/vnc-3.3.2_doc.tgz
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/vnc
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKDIR}/classes ${PREFIX}/share/vnc
.include <bsd.port.mk>
