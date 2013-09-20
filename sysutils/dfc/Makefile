# $FreeBSD$

PORTNAME=	dfc
PORTVERSION=	3.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.gw-computing.net/attachments/download/63/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Display file system space usage using graph and colors

LICENSE=	BSD

OPTIONS_DEFINE=	NLS

USES=		cmake
CMAKE_ARGS+=	-DMAN_PATH=${MANPREFIX}/man -DDFC_DOC_PATH=${DOCSDIR}
MANLANG=	"" fr
MAN1=		dfc.1

OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_ON=	-DNLS_ENABLED=true
NLS_CMAKE_OFF=	-DNLS_ENABLED=false

NO_STAGE=	yes
.include <bsd.port.mk>
