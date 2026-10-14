PORTNAME=	libnbd
PORTVERSION=	1.24.3
CATEGORIES=	net
MASTER_SITES=	https://download.libguestfs.org/${PORTNAME}/${PORTVERSION:R}-stable/

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	NBD client library in userspace
WWW=		https://gitlab.com/nbdkit/libnbd

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c11 gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-golang \
		--disable-ocaml \
		--disable-rust \
		--disable-ublk
INSTALL_TARGET=	install-strip

# Workaround for "fetch: transfer timed out" due to Hetzner's IPv6
# Same workaround as net/nbdkit.
FETCH_ARGS+=	--ipv4-only

OPTIONS_DEFINE=		BASH FUSE GNUTLS LIBXML2 MANPAGES PYTHON
OPTIONS_DEFAULT=	BASH FUSE GNUTLS LIBXML2 MANPAGES PYTHON
OPTIONS_SUB=		yes

LIBXML2_DESC=	URI support and nbdcopy/nbdinfo tools

BASH_BUILD_DEPENDS=	bash-completion>=2.0:shells/bash-completion
BASH_CONFIGURE_WITH=	bash-completions
BASH_CONFIGURE_ENV=	bashcompdir=${PREFIX}/share/bash-completion/completions

FUSE_USES=		fuse:3
FUSE_CONFIGURE_ENABLE=	fuse

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

LIBXML2_LIB_DEPENDS=	libxml2.so:textproc/libxml2
LIBXML2_CONFIGURE_WITH=	libxml2

MANPAGES_USES=			perl5
MANPAGES_USE=			PERL5=build
MANPAGES_CONFIGURE_ENV=		ac_cv_prog_PERL=${PERL}
MANPAGES_CONFIGURE_ENV_OFF=	ac_cv_prog_PERL=no

PYTHON_USES=			python
PYTHON_CONFIGURE_ON=		--with-python-installdir=${PYTHONPREFIX_SITELIBDIR}
PYTHON_CONFIGURE_ENABLE=	python

.include <bsd.port.mk>
