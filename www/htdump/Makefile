# Created by: Maxime Henrion (mux@FreeBSD.org)
# $FreeBSD$

PORTNAME=	htdump
PORTVERSION=	0.9y
CATEGORIES=	www
MASTER_SITES=	http://ivo.palli.nl/prog/linux/htdump/bin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to retrieve WWW data

LICENSE=	AL2

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

PLIST_FILES=	bin/htdump

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
ALL_TARGET=	ssl
.endif

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
