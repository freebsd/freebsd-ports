# Created by: trevor
# $FreeBSD$

PORTNAME=	mcrypt
PORTVERSION=	2.6.8
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/MCrypt/${PORTVERSION} \
		ftp://argeas.cs-net.gr/pub/unix/mcrypt/attic/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/attic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for crypt(1)

LIB_DEPENDS=	libmcrypt.so:security/libmcrypt \
		libmhash.so:security/mhash

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-static --with-catgets

OPTIONS_DEFINE=	DOCS NLS EXAMPLES
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/src/rfc2440.c

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd  ${WRKSRC}/doc && ${INSTALL_DATA} FORMAT magic ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
