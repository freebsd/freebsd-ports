# $FreeBSD$

PORTNAME=	jobd
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	mark@heily.com
COMMENT=	Job management framework

LICENSE=	ISCL

BUILD_DEPENDS=	docbook2mdoc:textproc/docbook2mdoc

HAS_CONFIGURE=	YES
USE_GITHUB=	YES
USE_LDCONFIG=	YES
GH_ACCOUNT=	mheily

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
