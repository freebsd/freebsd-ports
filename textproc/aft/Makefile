PORTNAME=	aft
PORTVERSION=	5.098
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.maplefish.com/todd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document preparation system using an Almost Free Text input format
WWW=		http://www.maplefish.com/todd/aft.html

LICENSE=	CART
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	Clarified Artistic License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Obscure markup language and unmaintained in tree for years
EXPIRATION_DATE=2025-04-30

USES=		perl5 gmake
GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
