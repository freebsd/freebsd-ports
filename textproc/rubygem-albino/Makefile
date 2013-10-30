# Created by: Steve Wills <swills@rubick>
# $FreeBSD$

PORTNAME=	albino
PORTVERSION=	1.3.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby wrapper for pygmentize

RUN_DEPENDS=	rubygem-posix-spawn>=0.3.6:${PORTSDIR}/devel/rubygem-posix-spawn \
		${PYTHON_PKGNAMEPREFIX}pygments>=0.8:${PORTSDIR}/textproc/py-pygments

USE_RUBY=	yes
USE_PYTHON=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
