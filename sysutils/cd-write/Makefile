# New ports collection makefile for:    cd-write
# Version required:     1.2
# Date created:         1 May 1997
# Whom:                 jmz
#
# $Id: Makefile,v 1.3 1997/05/19 21:28:26 jmz Exp $
#

DISTNAME=       cd-write-1.2
CATEGORIES=     sysutils
MASTER_SITES=   ftp://ftp.obs-besancon.fr/pub/outgoing/

MAINTAINER=     jmz@FreeBSD.org

LIB_DEPENDS=	tixsam4175\\.1\\.:${PORTSDIR}/x11/tix

WRKSRC=		${WRKDIR}/cd-write

pre-build:
	@cd ${WRKSRC}; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile;\
		echo all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; mv Makefile Makefile~; \
		sed -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

.include <bsd.port.mk>
