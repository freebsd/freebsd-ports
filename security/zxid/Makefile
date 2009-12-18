# New ports collection makefile for:	zxid
# Date created:		2007-07-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	zxid
PORTVERSION=	0.38
CATEGORIES=	security www
MASTER_SITES=	http://zxid.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Open Source IdM for the Masses - SAML SSO

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

MAKE_ARGS+=	CC="${CC}" CURL_ROOT="${LOCALBASE}" LD="${CC}" \
		PREFIX="${PREFIX}" OPENSSL_ROOT="${OPENSSLBASE}"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

post-install:

	${MKDIR} ${PREFIX}/include/zxid

	${INSTALL_PROGRAM} ${WRKSRC}/zxidhlo ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/zxididp ${PREFIX}/bin/

	${INSTALL_PROGRAM} ${WRKSRC}/libzxid.a      ${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/libzxid.so.0.0 ${PREFIX}/lib/libzxid.so.0
	${LN} -sf libzxid.so.0 ${PREFIX}/lib/libzxid.so

	(cd ${WRKSRC} && ${INSTALL_DATA} *.h c/*.h ${PREFIX}/include/zxid/)

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install
.endif

.include <bsd.port.post.mk>
