# Ports collection makefile for:  cvsync
# Date created:			  Thu Mar 6, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsync
PORTVERSION=	0.24.2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/ \
		ftp://ftp.allbsd.org/pub/cvsync/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A portable CVS repository synchronization utility

USE_GMAKE=	yes

MAN1=		cvscan.1 cvsync.1 cvsyncd.1 rcscan.1 rcscmp.1
DOCS=		doc/COPYRIGHT doc/ChangeLog doc/FAQ doc/TODO
EXAMPLES=	samples/cvsync.conf samples/cvsyncd.conf

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
