# ex:ts=8
# Ports collection makefile for:	libmsn
# Date created:			Feb 6, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libmsn
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://libmsn.bdash.net.nz/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for connecting to MSN Messenger service

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha" 
.endif

.include <bsd.port.post.mk>
