# ex:ts=8
# Ports collection makefile for:  kmap
# Date created:			  Fri Sep 10, 1999
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	kmap
PORTVERSION=	0.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.islc.net/~icszepp/downloads/

MAINTAINER=	obrien@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_QT=		yes

.include <bsd.port.mk>
