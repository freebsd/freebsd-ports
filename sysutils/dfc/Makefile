# $FreeBSD$

PORTNAME=	dfc
PORTVERSION=	3.0.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.gw-computing.net/attachments/download/467/

MAINTAINER=	mcy@lm7.fr
COMMENT=	Display file system space usage using graph and colors

LICENSE=	BSD3CLAUSE

USES=		cmake
CMAKE_ARGS+=	-DMAN_PATH=${MANPREFIX}/man -DDFC_DOC_PATH=${DOCSDIR}

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_ON=	-DNLS_ENABLED=true
NLS_CMAKE_OFF=	-DNLS_ENABLED=false

.include <bsd.port.mk>
