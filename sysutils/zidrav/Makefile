# New ports collection makefile for:   zidrav
# Date created:        14 July 2003
# Whom:                Cosmin Stroe <cstroe1@uic.edu>
#
# $FreeBSD$
#

PORTNAME=	zidrav
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://hehipc.phy.uic.edu/~cosmin/distfiles/:MAN\
		http://eff.dyndns.ws/distfiles/:MAN
MASTER_SITE_SUBDIR=	zidrav
DISTNAME=	zidrav4unix-1.1
DISTFILES=	zidrav4unix-1.1.tar.gz \
		zidrav.1.gz:MAN
EXTRACT_ONLY=	zidrav4unix-1.1.tar.gz

MAINTAINER=	cstroe1@uic.edu
COMMENT=	A file corruption detection and repair program

ALL_TARGET=	zidrav
MAN1=		zidrav.1.gz
MANCOMPRESSED=	maybe
NOMANCOMPRESS=	true
MANEXT=		# empty
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/zidrav

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/zidrav.1.gz ${MANPREFIX}/man/man1

.include <bsd.port.mk>
