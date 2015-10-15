# $FreeBSD$

PORTNAME=	polarssl
PORTVERSION=	1.2.17
DISTVERSIONSUFFIX=	-gpl
CATEGORIES=	security devel
MASTER_SITES=	https://polarssl.org/download/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Open Source embedded SSL/TLS cryptographic library

LICENSE=	GPLv2

ALL_TARGET=	no_test

USES=		cpe gmake tar:tgz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# PolarSSL's 1.3 branch introduces API changes that are served at this
# time by a separate polarssl13 port. Therefore, limit Portscout to the
# 1.2 branch for this port.
PORTSCOUT=	limit:^1\.2\.

DOCFILES=	ChangeLog README
BINFILES=	aescrypt2 benchmark dh_client dh_genprime dh_server hello \
		md5sum mpi_demo rsa_genkey rsa_sign rsa_verify selftest \
		sha1sum sha2sum ssl_cert_test ssl_client1 ssl_client2 \
		ssl_server ssl_test

OPTIONS_DEFINE=	DOCS TEST

.include <bsd.port.options.mk>

post-build:
	cd ${WRKSRC} && LD_LIBRARY_PATH="`pwd`/library" programs/test/selftest
post-build-TEST-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH="`pwd`/library" ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} check

# cmake install is broken, so we do it by hand
do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include "! -name *.orig"
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.so ${STAGEDIR}${PREFIX}/lib/libpolarssl.so.5
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpolarssl.so.5
	cd ${STAGEDIR}${PREFIX}/lib/ && ${LN} -sf libpolarssl.so.5 libpolarssl.so
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/programs/*/${i} ${STAGEDIR}${PREFIX}/bin/polarssl_${i}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

TEST_USES=	perl5

.include <bsd.port.mk>
