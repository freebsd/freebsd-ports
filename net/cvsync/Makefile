# Ports collection makefile for:  cvsync
# Date created:			  Thu Mar 6, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsync
PORTVERSION=	0.15.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.daemon-systems.org/cvsync/ \
		ftp://ftp.allbsd.org/pub/cvsync/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A portable CVS repository synchronization utility

USE_GMAKE=	yes

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
