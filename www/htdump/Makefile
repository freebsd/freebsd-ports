# Created by: Maxime Henrion (mux@FreeBSD.org)

PORTNAME=	htdump
PORTVERSION=	0.9y
CATEGORIES=	www
MASTER_SITES=	http://ivo.palli.nl/prog/linux/htdump/bin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to retrieve WWW data

LICENSE=	APACHE20

CONFLICTS_INSTALL=	htdig # bin/htdump

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

SSL_USES=	ssl
SSL_ALL_TARGET=	ssl
SSL_CFLAGS=	-I${OPENSSLINC}
SSL_LDFLAGS=	-L${OPENSSLLIB}

PLIST_FILES=	bin/htdump

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS|#CFLAGS| ; \
		 s|^CC|#CC| ; \
		 s|$$(LFLAGS)|$$(LDFLAGS)| ; \
		 s|-L/usr/local/ssl/lib|| ; \
		 s|%.o: %.c|| ; \
		 s|-I /usr/local/ssl/include|$$(CPPFLAGS)|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} htdump ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
