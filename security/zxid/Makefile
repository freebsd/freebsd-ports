# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	zxid
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://zxid.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Open Source IdM for the Masses - SAML SSO

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-D_LSEEK_DECLARED -fPIC
MAKE_ARGS=	CC="${CC}" CURL_ROOT="${LOCALBASE}" LD="${CC}" \
		PREFIX="${PREFIX}" OPENSSL_ROOT="${OPENSSLBASE}"
USES=		gmake
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

ZXID_BINS=	smime zxcall zxcot zxdecode zxencdectest zxid zxidhlo \
		zxidhlowsf zxidhrxmlwsc zxidhrxmlwsp zxididp zxidsimple \
		zxidwsctool zxlogview zxpasswd

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/which gcc/d' \
		-e 's/ --export-all-symbols/ /g' \
		${WRKSRC}/Makefile

post-install:
	${MKDIR} ${PREFIX}/include/zxid/
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ${ZXID_BINS} ${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libzxid.a ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libzxid.so.0.0 ${PREFIX}/lib/libzxid.so.0
	${LN} -sf libzxid.so.0 ${PREFIX}/lib/libzxid.so
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.h c/*.h ${PREFIX}/include/zxid/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.pd ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install
.endif

.include <bsd.port.post.mk>
