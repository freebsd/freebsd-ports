PORTNAME=	tpm-quote-tools
DISTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/tpmquotetools/${PORTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Tools for TPM-based remote attestation using the TPM quote operation
WWW=		https://sourceforge.net/projects/tpmquotetools/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtspi.so:security/trousers

USES=		iconv localbase:ldflags ssl

GNU_CONFIGURE=	YES
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
