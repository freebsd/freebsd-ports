# $FreeBSD: head/net/tinyfugue/Makefile 525173 2020-02-04 16:17:25Z dinoex $

PORTNAME=	tinyfugue
PORTVERSION=	5.1.3
PORTREVISION=	0
CATEGORIES=	net games
PKGNAMESUFFIX=	-devel${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Popular programmable MUD client, with macro support and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	ingwarsw

USES=		ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-manpage --enable-version --enable-symlink \
		--exec-prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--mandir=${PREFIX}/man \
		--datadir=${PREFIX}/lib --with-inclibpfx=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}
PLIST_SUB=	DISTNAME=tf-development

post-build:
	${STRIP_CMD} ${WRKSRC}/src/tf

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/tf.1.nroffman ${STAGEDIR}${PREFIX}/man/man1/tf-development.1
	${RM} ${STAGEDIR}${PREFIX}/bin/tf

.include <bsd.port.mk>
