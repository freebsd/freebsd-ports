# New ports collection makefile for:    cd-write
# Version required:     1.4
# Date created:         1 May 1997
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1997/06/02 21:28:46 jmz Exp $
#

DISTNAME=       cd-write-1.4
CATEGORIES=     sysutils
MASTER_SITES=   ftp://ftp.obs-besancon.fr/pub/outgoing/

MAINTAINER=     jmz@FreeBSD.org

LIB_DEPENDS=	tixsam4176\\.1\\.:${PORTSDIR}/x11/tix

WRKSRC=		${WRKDIR}/cd-write

pre-build:
	@cd ${WRKSRC}; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile;\
		echo all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

.include <bsd.port.mk>
