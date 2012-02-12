# New ports collection makefile for:	zxid
# Date created:		2007-07-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	zxid
PORTVERSION=	1.05
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
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

ZXID_BINS=	smime zxcall zxcot zxdecode zxencdectest zxid zxidhlo \
		zxidhlowsf zxidhrxmlwsc zxidhrxmlwsp zxididp zxidsimple \
		zxidwsctool zxlogview zxpasswd

post-install:
	${MKDIR} ${PREFIX}/include/zxid/
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ${ZXID_BINS} ${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libzxid.a ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libzxid.so.0.0 ${PREFIX}/lib/libzxid.so.0
	${LN} -sf libzxid.so.0 ${PREFIX}/lib/libzxid.so
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.h c/*.h ${PREFIX}/include/zxid/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.pd ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install
.endif

.include <bsd.port.post.mk>
