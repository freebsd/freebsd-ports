# Created by: Oleg Ginzburg
# $FreeBSD$

PORTNAME=	retail
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://xjack.org/retail/download/ \
		http://www.bsdstore.ru/downloads/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Program for incremental logfile reader

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/retail man/man1/retail.1.gz

post-configure:
	${REINPLACE_CMD} -e 's/%.o: %.c \*.h ..\/config.h//g' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/retail.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
