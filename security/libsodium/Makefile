# $FreeBSD$

PORTNAME=	libsodium
PORTVERSION=	0.4.2
CATEGORIES=	security
MASTER_SITES=	http://download.dnscrypt.org/libsodium/releases/

MAINTAINER=	csosstudy@gmail.com
COMMENT=	Library to build higher-level cryptographic tools

LICENSE=	ISCL

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS THANKS

post-build:
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
