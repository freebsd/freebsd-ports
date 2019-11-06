# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	tracdragdrop
PORTVERSION=	0.12.0.10.${SVN_REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		http://trac-hacks.org/changeset/${SVN_REV}/tracdragdropplugin?old_path=/&format=zip&filename=/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	gaod@hychen.org
COMMENT=	Provides extends attachments list of Trac

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	tracd:www/trac

SVN_REV=	12822

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

.include <bsd.port.mk>
