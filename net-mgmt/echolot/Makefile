# ex:ts=8
# Ports collection makefile for:	echolot
# Date created:			Jun 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	echolot
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITES=	http://echolot.sourceforge.net/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A packet sniffer that grabs ARP packets on any ethernet devices

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	echolot.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
