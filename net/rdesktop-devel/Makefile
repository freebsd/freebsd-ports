# New ports collection makefile for:  rdesktop
# Date created:               13 December 2000
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	rdesktop
PORTVERSION=	1.1.0.p19.8.2
CATEGORIES=	net comms
MASTER_SITES=	http://bibl4.oru.se/projects/rdesktop/dist/releases/
DISTNAME=	rdesktop-1.1.0

PATCH_SITES=	http://bibl4.oru.se/projects/rdesktop/ \
		http://bibl4.oru.se/projects/rdesktop/patch19/
PATCHFILES=	rdesktop-unified-patch19-8-2.bz2
PATCH_DIST_STRIP=	-p2

MAINTAINER=	chris@aims.com.au

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl

MAN1=		rdesktop.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rdesktop ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/rdesktop.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
