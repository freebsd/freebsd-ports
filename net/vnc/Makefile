# New ports collection makefile for:	vnc
# Date created:		24 February 1998
# Whom:			msmith
#
# $FreeBSD$
#

PORTNAME=	vnc
PORTVERSION=	3.3.3.2
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.uk.research.att.com/vnc/dist/ \
		ftp://ftp.uk.research.att.com/pub/vnc/dist/
DISTFILES=	vnc-3.3.3r2_unixsrc.tgz \
		vnc-latest_doc.tgz
EXTRACT_ONLY=	vnc-3.3.3r2_unixsrc.tgz

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	vnc-3.3.3r2-v6-20010421.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

USE_PERL5=	yes
IGNOREFILES=	vnc-latest_doc.tgz
WRKSRC=		${WRKDIR}/vnc_unixsrc
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
ALL_TARGET=	World

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${PREFIX}/bin/vncconnect
	${SED}  -e s%/usr/local/vnc/classes%${PREFIX}/share/vnc/classes% \
		-e s%^\#!/usr/bin/perl%\#!${PERL}% \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${PREFIX}/share/vnc
.if !defined(NOPORTDOCS)
# The documentation comes with bogus ownerships; this is a little leaky
# security-wise
	${TAR} -C ${PREFIX}/share/doc -xzf ${DISTDIR}/vnc-latest_doc.tgz
	(cd ${PREFIX}/share/doc; ${RM} -rf vnc; ${MV} vnc_docs vnc)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/vnc
# Add to PLIST because VNC developers can't/won't freeze their doc
# distfile.
	(cd ${PREFIX}; ls share/doc/vnc/* >> ${TMPPLIST})
	${ECHO_CMD} '@dirrm share/doc/vnc' >> ${TMPPLIST}
.endif
.include <bsd.port.mk>
