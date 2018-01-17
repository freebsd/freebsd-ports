# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tblis
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Framework for performing tensor operations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	i386 requires SSE

OPTIONS_DEFINE=	PARA
PARA_DESC=	use pthread parallelization
OPTIONS_DEFAULT=	PARA

USE_GITHUB=	yes
GH_ACCOUNT=	devinamatthews

USES=		gmake libtool
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes

PARA_CONFIGURE_ON=	--enable-thread-model=pthreads
PARA_CONFIGURE_OFF=	--enable-thread-model=none

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
