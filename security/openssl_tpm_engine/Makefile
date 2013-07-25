# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	openssl_tpm_engine
PORTVERSION=	0.4.2
CATEGORIES=	security
MASTER_SITES=	SF/trousers/OpenSSL%20TPM%20Engine/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OpenSSL TPM engine

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:${PORTSDIR}/security/trousers
LIB_DEPENDS=	tspi:${PORTSDIR}/security/trousers

USES=	gmake
USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
SUB_FILES=	pkg-message
PORTEXAMPLES=	openssl.cnf.sample

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/openssl.cnf.sample

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/openssl.cnf.sample ${EXAMPLESDIR}
.endif
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.mk>
