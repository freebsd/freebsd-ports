PORTNAME=	czmq
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/zeromq/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-level C Binding for ZeroMQ
WWW=		http://czmq.zeromq.org

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE} \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	PORTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_USES=		perl5 shebangfix
MANPAGES_USE=	PERL5=build
MANPAGES_CONFIGURE_WITH=	docs
MANPAGES_VARS=	SHEBANG_FILES=doc/mkman

.include <bsd.port.mk>
