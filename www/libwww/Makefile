# Created by: torstenb
# $FreeBSD$

PORTNAME=	libwww
PORTVERSION=	5.4.0
PORTREVISION=	6
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/old/
DISTNAME=	w3c-${PORTNAME}-${PORTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	W3C Reference Library

LICENSE=	W3C
LICENSE_NAME=	W3C IPR SOFTWARE NOTICE
LICENSE_FILE=	${WRKSRC}/LICENSE.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib --with-ssl=${OPENSSLBASE}
USES=		gmake libtool perl5 ssl tar:tgz
USE_PERL5=	build
USE_LDCONFIG=	yes

BROKEN_SSL=		openssl-devel

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/expat/xmlparse/xmlparse.h \
		${STAGEDIR}${PREFIX}/include/w3c-libwww/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
