PORTNAME=	nbdkit
PORTVERSION=	1.44.4
CATEGORIES=	net
# XXX Although nbdkit uses github for its homepage, the release tarballs served
# by github haven't been through autoconf.  So we must download the sources
# from libguestfs.org instead.
MASTER_SITES=	http://download.libguestfs.org/${PORTNAME}/${PORTVERSION:R}-stable/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Network Block Device server toolkit with stable ABI and permissive license
WWW=		https://gitlab.com/nbdkit/nbdkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash-completion>0:shells/bash-completion \
		bash:shells/bash

USES=		compiler:c11 cpe gmake libtool pkgconfig

CPE_VENDOR=	nbdkit_project
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
# Rust consumers will download the Rust plugin from crates.io
CONFIGURE_ARGS+=	--disable-rust
# These libraries does not exist on ports
CONFIGURE_ARGS+=	--without-libguestfs \
			--without-libnbd
# We could theoretically build these other plugins, if anybody cares to.
CONFIGURE_ARGS+=	--disable-golang \
			--disable-linuxdisk \
			--disable-lua \
			--disable-ocaml \
			--disable-tcl \
			--disable-vddk \
			--without-ext2 \
			--without-iso

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	CURL GNUTLS LIBVIRT LZMA MANPAGES PERL PYTHON RUBY SSH ZLIB \
		ZSTD

OPTIONS_DEFAULT=	GNUTLS MANPAGES
OPTIONS_SUB=		yes

CURL_BUILD_DEPENDS+=		curl:ftp/curl
CURL_RUN_DEPENDS+=		curl:ftp/curl
CURL_CONFIGURE_WITH=		curl
GNUTLS_BUILD_DEPENDS=		gnutls>0:security/gnutls
GNUTLS_RUN_DEPENDS=		gnutls>0:security/gnutls
LIBVIRT_LIB_DEPENDS=		libvirt.so:devel/libvirt
LIBVIRT_CONFIGURE_WITH=		libvirt
LZMA_LIB_DEPENDS=		liblzma.so:archivers/lzmalib
LZMA_CONFIGURE_WITH=		liblzma
MANPAGES_USES+=			perl5
MANPAGES_USE+=			PERL5=build
PERL_USE+=			perl5
PERL_CONFIGURE_ENABLE=		perl
PYTHON_USES+=			python
PYTHON_CONFIGURE_ENABLE=	python
RUBY_USE+=			ruby
RUBY_CONFIGURE_ENABLE=		ruby
SSH_LIB_DEPENDS=		libssh.so:security/libssh
SSH_CONFIGURE_WITH=		ssh
ZLIB_CONFIGURE_WITH=		zlib
ZSTD_LIB_DEPENDS=		libzstd.so:archivers/zstd
ZSTD_CONFIGURE_WITH=		libzstd

.include <bsd.port.mk>
