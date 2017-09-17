# $FreeBSD$

PORTNAME=	tayga
PORTVERSION=	0.9.2
CATEGORIES=	net
MASTER_SITES=	http://www.litech.org/tayga/

MAINTAINER=	melifaro@FreeBSD.org
COMMENT=	Userland stateless NAT64 daemon

LICENSE=	GPLv2

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

USE_HARDENING=	safestack

post-configure:
	@${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS ?=|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
