# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smp_utils
PORTVERSION=	0.98
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/
EXTRACT_SUFX=	.tgz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Utilities to send SAS Serial Management Protocol requests

USES=		gmake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
IGNORE=		requires FreeBSD 9.x
.endif

.include <bsd.port.post.mk>
