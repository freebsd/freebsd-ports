# ex:ts=8
# Ports collection makefile for:  kmap
# Version required:     	  0.4
# Date created:			  Fri Sep 10, 1999
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	kmap-0.4
CATEGORIES=	security net
MASTER_SITES=	http://www.islc.net/~icszepp/kmap/

MAINTAINER=     obrien@FreeBSD.org

LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_QT=		yes

.include <bsd.port.mk>
