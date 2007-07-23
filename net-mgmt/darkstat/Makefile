# New ports collection makefile for:	darkstat
# Date created:				24 February 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darkstat
PORTVERSION=	3.0.619
CATEGORIES=	net-mgmt
MASTER_SITES=	http://dmr.ath.cx/net/darkstat/

MAINTAINER=	emil@cs.rmit.edu.au
COMMENT=	Network statistics gatherer and reporter

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	darkstat.1
DOCS=	AUTHORS INSTALL README THANKS

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
