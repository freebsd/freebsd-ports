# $FreeBSD$

PORTNAME=	rouge
PORTVERSION=	2.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, easy-to-extend drop-in replacement for pygments

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes
PLIST_FILES=	bin/rougify

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
