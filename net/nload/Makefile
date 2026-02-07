PORTNAME=	nload
DISTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.roland-riegel.de/nload/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Console application which monitors network traffic in real time
WWW=		http://www.roland-riegel.de/nload/

LICENSE=	GPLv2

USES=				ncurses
GNU_CONFIGURE=			yes

PLIST_FILES=	bin/nload \
		share/man/man1/nload.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s|\(/etc/nload\.conf\)|${PREFIX}\1|" \
		${WRKSRC}/docs/nload.1.in ${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
