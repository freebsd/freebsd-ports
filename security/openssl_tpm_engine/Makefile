# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	openssl_tpm_engine
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/trousers/OpenSSL%20TPM%20Engine/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSSL TPM engine

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:${PORTSDIR}/security/trousers
LIB_DEPENDS=	libtspi.so:${PORTSDIR}/security/trousers

USES=		gmake libtool
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lcrypto
CFLAGS+=	-I${LOCALBASE}/include
SUB_FILES=	pkg-message
PORTEXAMPLES=	openssl.cnf.sample

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/openssl.cnf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/openssl.cnf.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
