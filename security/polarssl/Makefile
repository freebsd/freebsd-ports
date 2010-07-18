# New ports collection makefile for:    polarssl
# Date created:         10 Dec 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	polarssl
PORTVERSION=	0.13.1
DISTVERSIONSUFFIX=	-gpl
CATEGORIES=	security devel
MASTER_SITES=	http://polarssl.org/code/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Open Source embedded SSL/TLS cryptographic library

LICENSE=	GPLv2

USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	ChangeLog LICENSE README

BINFILES=	aescrypt2 benchmark dh_client dh_genprime dh_server hello \
		md5sum mpi_demo rsa_genkey rsa_sign rsa_verify selftest \
		sha1sum sha2sum ssl_cert_test ssl_client1 ssl_client2 \
		ssl_server ssl_test

# cmake install is broken, so we do it by hand
do-install:
	@${TAR} -C ${WRKSRC}/include -cf - polarssl | ${TAR} -C ${PREFIX}/include -xf -
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.a ${PREFIX}/lib/
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/programs/*/${i} ${PREFIX}/bin/polarssl_${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
