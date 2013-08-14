# $FreeBSD$

PORTNAME=	polarssl
PORTVERSION=	1.2.8
DISTVERSIONSUFFIX=	-gpl
CATEGORIES=	security devel
MASTER_SITES=	http://polarssl.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Open Source embedded SSL/TLS cryptographic library

LICENSE=	GPLv2

# bypass the HTML "now downloading..." splash site, code below
# .include <bsd.port.pre.mk>
URL_SUFFIX=	?do=yes
FETCH_ARGS=	-pRro ${DISTFILES}
ALL_TARGET=	no_test

USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	ChangeLog README

BINFILES=	aescrypt2 benchmark dh_client dh_genprime dh_server hello \
		md5sum mpi_demo rsa_genkey rsa_sign rsa_verify selftest \
		sha1sum sha2sum ssl_cert_test ssl_client1 ssl_client2 \
		ssl_server ssl_test

# cmake install is broken, so we do it by hand
do-install:
	@${TAR} -C ${WRKSRC}/include -cf - polarssl | ${TAR} -C ${PREFIX}/include -xf -
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.so  ${PREFIX}/lib/libpolarssl.so.0
	cd ${PREFIX}/lib/ && ${LN} -sf libpolarssl.so.0 libpolarssl.so
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/programs/*/${i} ${PREFIX}/bin/polarssl_${i}
.endfor

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

FETCH_CMD=	${SH} ${FILESDIR}/fetchwrapper.sh \
			${URL_SUFFIX} ${FETCH_BINARY} ${FETCH_ARGS}

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
