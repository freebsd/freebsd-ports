# $FreeBSD$

PORTNAME=	mercurial
PORTVERSION=	1.0.0.3
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/rm
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
DIST_SUBDIR=	trac

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Plugin to use Mercurial instead of Subversion in Trac

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	hg:devel/mercurial \
		tracd:www/trac

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
