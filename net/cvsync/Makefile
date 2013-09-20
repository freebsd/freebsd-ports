# $FreeBSD$

PORTNAME=	cvsync
PORTVERSION=	0.24.19
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/ \
		ftp://ftp.allbsd.org/pub/cvsync/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A portable CVS repository synchronization utility

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/COPYRIGHT

USE_GMAKE=	yes
USE_RC_SUBR=	cvsyncd
USE_OPENSSL=	yes

MAN1=		cvscan.1 cvsup2cvsync.1 cvsync.1 cvsync2cvsup.1 cvsyncd.1 \
		rcscan.1 rcscmp.1
PORTDOCS=	ChangeLog FAQ TODO
PORTEXAMPLES=	cvsync.conf cvsyncd-FreeBSD.conf \
		cvsyncd-NetBSD.conf cvsyncd-OpenBSD.conf

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_FLAGS=	OSVER="${OSVERSION}" HASH_TYPE=openssl

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
