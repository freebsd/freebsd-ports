# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	0.9.3
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Toolkit for Encryption, Signatures and Certificates Based on OpenSSL

LICENSE=	MIT

USES=	cran:auto-plist

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
R_POSTCMD_INSTALL_OPTIONS+=	--configure-vars="INCLUDE_DIR=${OPENSSLINC} LIB_DIR=${OPENSSLLIB}"
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/bin\//s|bash|sh|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
