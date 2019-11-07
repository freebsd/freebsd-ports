# Created by: minoura@netbsd.org
# $FreeBSD$

PORTNAME=	xcruiser
PORTVERSION=	0.30
PORTREVISION=	3
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Navigate through a three-dimensional view of a file system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
