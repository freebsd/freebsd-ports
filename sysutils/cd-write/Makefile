# New ports collection makefile for:    cd-write
# Version required:     1.1
# Date created:         1 May 1997
# Whom:                 jmz
#
# $Id$
#

DISTNAME=       cd-write-1.1
CATEGORIES=     sysutils x11
MASTER_SITES=   ftp://ftp.obs-besancon.fr/pub/outgoing/

MAINTAINER=     jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/cd-write

LIB_DEPENDS=	tixsam4175\\.1\\.:${PORTSDIR}/x11/tix

pre-build:
	@cd ${WRKSRC}; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile;\
		echo all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

.include <bsd.port.mk>
