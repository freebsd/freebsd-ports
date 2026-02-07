PORTNAME=	starttls
PORTVERSION=	0.10
PORTREVISION=	36
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.opaopa.org/pub/elisp/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple wrapper program for STARTTLS on ${EMACS_PORT_NAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
