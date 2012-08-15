# New ports collection makefile for:	openssl_tpm_engine
# Date created:				18 Sep 2007
# Whom:					Sebastian Schuetz <sschuetz@fhm.edu>
#
# $FreeBSD$
#

PORTNAME=	openssl_tpm_engine
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/trousers/OpenSSL%20TPM%20Engine/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSSL TPM engine

RUN_DEPENDS=	${LOCALBASE}/sbin/tcsd:${PORTSDIR}/security/trousers
LIB_DEPENDS=	tspi.2:${PORTSDIR}/security/trousers

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=	YES
USE_AUTOTOOLS=	autoconf libtool
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

.include <bsd.port.pre.mk>
CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/openssl.cnf.sample

post-install:
	@[ -d ${EXAMPLESDIR} ] || ${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/openssl.cnf.sample ${EXAMPLESDIR}
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.post.mk>
