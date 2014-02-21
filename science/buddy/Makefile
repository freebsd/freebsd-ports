# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	buddy
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/BuDDy%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Binary Decision Diagram library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes

DOCS=		doc/bddnotes.ps doc/buddy.ps doc/tech.txt README AUTHORS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
