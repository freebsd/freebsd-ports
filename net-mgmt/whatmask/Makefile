# Created by: ijliao
# $FreeBSD$

PORTNAME=	whatmask
PORTVERSION=	1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/whatmask/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily convert between three common subnet mask notations

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

DOCS=		AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
