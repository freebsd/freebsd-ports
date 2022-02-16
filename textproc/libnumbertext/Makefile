PORTNAME=	libnumbertext
PORTVERSION=	1.0.8
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/Numbertext/libnumbertext/releases/download/${PORTVERSION}/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Number to number name and money text conversion libraries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake libtool tar:xz

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
