PORTNAME=	starttls
PORTVERSION=	0.10
PORTREVISION=	23
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.opaopa.org/pub/elisp/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple wrapper program for STARTTLS on ${EMACS_PORT_NAME}

USES=		emacs gmake ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
