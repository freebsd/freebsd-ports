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
USE_GMAKE=	yes
USE_LDCONFIG=	yes

DOCS=		doc/bddnotes.ps doc/buddy.ps doc/tech.txt README AUTHORS

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
