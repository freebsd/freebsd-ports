PORTNAME=	nemesis
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8-5
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gb1d398c
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command-line network packet crafting and injection utility

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnet.so:net/libnet

USES=		autoreconf gmake localbase:ldflags

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libnet

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR} # DOCSDIR doesn't have anything valuable

.include <bsd.port.mk>
