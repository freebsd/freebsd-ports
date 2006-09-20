# New ports collection makefile for:	mhash
# Date created:		Mon Jun 28 17:59:13 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	0.9.7.1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An easy-to-use library for strong hashes such as MD5 and SHA1

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-LDFLAGS="${PTHREAD_LIBS}" --enable-static \
			--with-gnu-ld

MAN3=		mhash.3

PORTDOCS=	example.c md5-rfc1321.txt skid2-authentication

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
