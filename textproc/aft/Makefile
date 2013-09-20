# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aft
PORTVERSION=	5.098
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.maplefish.com/todd/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	A document preparation system using an Almost Free Text input format

USES=		perl5
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-binSCRIPTS install-pkgdataDATA install-pkgdataSCRIPTS
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
