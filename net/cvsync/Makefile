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

PORTDOCS=	ChangeLog FAQ TODO
PORTEXAMPLES=	cvsync.conf cvsyncd-FreeBSD.conf \
		cvsyncd-NetBSD.conf cvsyncd-OpenBSD.conf

MAKE_ENV+=	DESTDIR="${STAGEDIR}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		INSTALL= \
		INSTALL_BIN_OPTS="${INSTALL_PROGRAM}" \
		INSTALL_MAN_OPTS="${INSTALL_MAN}"
MAKE_FLAGS=	OSVER="${OSVERSION}" HASH_TYPE=openssl

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
