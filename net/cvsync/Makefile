# Ports collection makefile for:  cvsync
# Date created:			  Thu Mar 6, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsync
PORTVERSION=	0.24.15
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/ \
		ftp://ftp.allbsd.org/pub/cvsync/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A portable CVS repository synchronization utility

USE_GMAKE=	yes

MAN1=		cvscan.1 cvsup2cvsync.1 cvsync.1 cvsyncd.1 rcscan.1 rcscmp.1
DOCS=		doc/COPYRIGHT doc/ChangeLog doc/FAQ doc/TODO
EXAMPLES=	samples/cvsync.conf samples/cvsyncd-FreeBSD.conf \
		samples/cvsyncd-NetBSD.conf samples/cvsyncd-OpenBSD.conf

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_FLAGS=	OSVER="${OSVERSION}"

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
MAKE_FLAGS+=	HASH_TYPE=openssl
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
