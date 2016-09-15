# $FreeBSD$

PORTNAME=	starttls
PORTVERSION=	0.10
PORTREVISION=	15
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.opaopa.org/pub/elisp/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Simple wrapper program for STARTTLS on ${EMACS_PORT_NAME}

GNU_CONFIGURE=	yes
USES=		gmake ssl
USE_EMACS=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
