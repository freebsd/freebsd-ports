# $FreeBSD$

PORTNAME=	polarssl
PORTVERSION=	1.2.10
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

USES=	gmake
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# PolarSSL 1.3 branch introduces API changes that would best be served at this
# time by a new/seperate polarssl13 port. Therefore, limit Portscout to the
# 1.2 branch for this port.
PORTSCOUT=	limit:^1\.2\.

DOCFILES=	ChangeLog README
BINFILES=	aescrypt2 benchmark dh_client dh_genprime dh_server hello \
		md5sum mpi_demo rsa_genkey rsa_sign rsa_verify selftest \
		sha1sum sha2sum ssl_cert_test ssl_client1 ssl_client2 \
		ssl_server ssl_test

# cmake install is broken, so we do it by hand
do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include "! -name *.orig"
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/library/libpolarssl.so  ${STAGEDIR}${PREFIX}/lib/libpolarssl.so.0
	cd ${STAGEDIR}${PREFIX}/lib/ && ${LN} -sf libpolarssl.so.0 libpolarssl.so
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/programs/*/${i} ${STAGEDIR}${PREFIX}/bin/polarssl_${i}
.endfor

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

FETCH_CMD=	${SH} ${FILESDIR}/fetchwrapper.sh \
			${URL_SUFFIX} ${FETCH_BINARY} ${FETCH_ARGS}

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
