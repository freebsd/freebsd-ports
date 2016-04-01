# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	tracdragdrop
PORTVERSION=	0.12.0.10.${SVN_REV}
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		http://trac-hacks.org/changeset/${SVN_REV}/tracdragdropplugin?old_path=/&format=zip&filename=/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	gaod@hychen.org
COMMENT=	Provides extends attachments list of Trac

LICENSE=	BSD3CLAUSE

SVN_REV=	12822

RUN_DEPENDS+=	tracd:www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
USES=		python:2 zip
USE_PYTHON=	distutils autoplist

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
