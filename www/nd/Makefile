# New ports collection makefile for:	nd
# Date created:			Sep 4, 2002
# Whom:				Volker Stolz <stolz+nd@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	nd
PORTVERSION=	0.8.2
CATEGORIES=	www
MASTER_SITES=	http://www.gohome.org/nd/

MAINTAINER=	stolz+nd@i2.informatik.rwth-aachen.de
COMMENT=	A simple command line interface for WebDAV (RFC2518) server

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes

MAN1=		nd.1
PLIST_FILES=	bin/nd

.include <bsd.port.mk>
