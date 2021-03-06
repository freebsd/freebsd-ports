# $FreeBSD$

PORTNAME=	nbdkit
PORTVERSION=	1.20.4
PORTREVISION=	1
CATEGORIES=	net
# XXX Although nbdkit uses github for its homepage, the release tarballs served
# by github haven't been through autoconf.  So we must download the sources
# from libguestfs.org instead.
MASTER_SITES=	http://download.libguestfs.org/${PORTNAME}/${PORTVERSION:R}-stable/

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Network Block Device server toolkit with stable ABI and permissive license

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		bash-completion>0:shells/bash-completion

USES=		compiler:c11 gmake libtool pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

# Rust consumers will download the Rust plugin from crates.io
CONFIGURE_ARGS+=	--disable-rust
# These libraries does not exist on ports
CONFIGURE_ARGS+=	--without-libnbd
CONFIGURE_ARGS+=	--without-libguestfs
# We could theoretically build these other plugins, if anybody cares to.
CONFIGURE_ARGS+=	--disable-ocaml
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-golang
CONFIGURE_ARGS+=	--disable-vddk
CONFIGURE_ARGS+=	--without-ext2
CONFIGURE_ARGS+=	--without-iso
CONFIGURE_ARGS+=	--without-linuxdisk
USE_LDCONFIG=		yes

OPTIONS_DEFINE=	CURL GNUTLS LIBVIRT LZMA MANPAGES PERL PYTHON RUBY SSH ZLIB
GNUTLS_BUILD_DEPENDS=	gnutls>0:security/gnutls
GNUTLS_RUN_DEPENDS=	gnutls>0:security/gnutls

OPTIONS_DEFAULT=	GNUTLS MANPAGES
OPTIONS_SUB=		yes

CURL_BUILD_DEPENDS+=	curl:ftp/curl
CURL_CONFIGURE_WITH=	curl
CURL_RUN_DEPENDS+=	curl:ftp/curl
LIBVIRT_CONFIGURE_WITH=	libvirt
LIBVIRT_LIB_DEPENDS=	libvirt.so:devel/libvirt
LZMA_CONFIGURE_WITH=	liblzma
LZMA_LIB_DEPENDS=	liblzma.so:archivers/lzmalib
MANPAGES_USE+=		perl5=build
MANPAGES_USES+=		perl5
PERL_CONFIGURE_ENABLE=	perl
PERL_USE+=		perl5
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USES+=		python:3.3+
RUBY_CONFIGURE_ENABLE=	ruby
RUBY_USE+=		ruby
SSH_CONFIGURE_WITH=	ssh
SSH_LIB_DEPENDS=	libssh.so:security/libssh
ZLIB_CONFIGURE_WITH=	zlib

.include <bsd.port.mk>
