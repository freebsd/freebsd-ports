PORTNAME=	retail
DISTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://xjack.org/retail/download/ \
		http://www.bsdstore.ru/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for incremental logfile reader
WWW=		http://xjack.org/retail/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/retail share/man/man1/retail.1.gz

post-configure:
	${REINPLACE_CMD} -e 's/%.o: %.c \*.h ..\/config.h//g; \
		s|man/man1|share/man/man1|g' ${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
