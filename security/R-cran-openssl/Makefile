# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	0.9.5
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Toolkit for Encryption, Signatures and Certificates Based on OpenSSL

LICENSE=	MIT

USES=		cran:auto-plist,compiles ssl

R_POSTCMD_INSTALL_OPTIONS+=	--configure-vars="INCLUDE_DIR=${OPENSSLINC} LIB_DIR=${OPENSSLLIB}"

post-patch:
	${REINPLACE_CMD} -e '1,5d' ${WRKSRC}/src/ssl.c

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
IGNORE=	Detected LibreSSL (missing RSA_get0_key and others)
.else
. if ${OSVERSION} < 1000015 && ${SSL_DEFAULT:Mbase}
IGNORE=	Need a more recent version of OpenSSL.
. endif
.endif

.include <bsd.port.post.mk>
