# New ports collection makefile for:	vnc
# Version required:     3.3.2r3
# Date created:		24 February 1998
# Whom:			msmith
#
# $Id: Makefile,v 1.9 1999/01/07 06:35:14 steve Exp $
#

DISTNAME=       	vnc-3.3.2r3_unixsrc
PKGNAME=        	vnc-3.3.2r3
CATEGORIES=		net
MASTER_SITES=   	http://www.uk.research.att.com/vnc/dist/
DISTFILES=		vnc-3.3.2r3_unixsrc.tgz \
			vnc-3.3.2_doc.tgz

MAINTAINER=	 	bmah@ca.sandia.gov

USE_PERL5=		YES

EXTRACT_ONLY=		vnc-3.3.2r3_unixsrc.tgz
IGNOREFILES=		${DISTFILES}

WRKSRC=			${WRKDIR}/vnc_unixsrc

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

ALL_TARGET=    		World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${SED}  -e s%/usr/local/vnc/classes%${PREFIX}/share/vnc/classes% \
		-e s%^\#!/usr/bin/perl%\#!${PERL}% \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
# The documentation comes with bogus ownerships; this is a little leaky security-wise
	${MKDIR} ${PREFIX}/share/doc/vnc
	tar -C ${PREFIX}/share/doc/vnc -xzf ${DISTDIR}/vnc-3.3.2_doc.tgz
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/vnc
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${PREFIX}/share/vnc
.include <bsd.port.mk>
