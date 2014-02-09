# $FreeBSD$

PORTNAME=	mercurial
PORTVERSION=	1.0.0.3
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/rm
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
DIST_SUBDIR=	trac

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin to use Mercurial instead of Subversion in Trac

LICENSE=	GPLv2

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
