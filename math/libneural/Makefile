# Created by: will
# $FreeBSD$

PORTNAME=	libneural
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ implementation of the classic 3-layer perceptron in library form

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
