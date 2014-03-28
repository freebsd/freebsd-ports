# Created by: torstenb
# $FreeBSD$

PORTNAME=	libwww
PORTVERSION=	5.4.0
PORTREVISION=	4
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/
DISTNAME=	w3c-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	marius@nuenneri.ch
COMMENT=	The W3C Reference Library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static --with-zlib --with-ssl=${OPENSSLBASE}
USES=		perl5 gmake
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/expat/xmlparse/xmlparse.h \
		${STAGEDIR}${PREFIX}/include/w3c-libwww/

.include <bsd.port.mk>
