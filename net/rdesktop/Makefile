# New ports collection makefile for:  rdesktop
# Date created:               13 December 2000
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	rdesktop
PORTVERSION=	1.0.0.p19.7.4
CATEGORIES=	net comms
MASTER_SITES=	http://bibl4.oru.se/projects/rdesktop/dist/releases/
DISTNAME=	rdesktop-1.0.0

PATCH_SITES=	http://bibl4.oru.se/projects/rdesktop/ \
		http://bibl4.oru.se/projects/rdesktop/patch19/
PATCHFILES=	rdesktop-unified-patch19-7-4.bz2
PATCH_DIST_STRIP=	-p2

MAINTAINER=	chris@aims.com.au

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

MAN1=		rdesktop.1
ALL_TARGET=

do-patch:
	@${EXTRACT_CMD} -dc ${_DISTDIR}/${PATCHFILES} | \
		${PATCH} ${PATCH_DIST_ARGS}
	@${PERL} -pi.orig -e 's:-O2.*-Wall:${CFLAGS}:g' ${WRKSRC}/Makefile
	@${PERL} -pi.orig -e 's:/usr/X11R6/:${X11BASE}/:g' ${WRKSRC}/Makefile
	@${PERL} -pi.orig -e 's:^PREFIX.*:PREFIX=${PREFIX}:g' ${WRKSRC}/Makefile
	@${PERL} -pi.orig -e 's:^install.*:install\: rdesktop:g' ${WRKSRC}/Makefile
	@${PERL} -pi.orig -e 's:^.*\(INSTALL\) rdp-srvr.*::g' ${WRKSRC}/Makefile
	@${PERL} -pi.orig -e 's:<endian.h>:<machine/endian.h>:g' ${WRKSRC}/rdesktop.h

.include <bsd.port.mk>
