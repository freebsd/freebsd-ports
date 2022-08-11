PORTNAME=	lynx
PORTVERSION=	2.9.0d10
CATEGORIES=	www
MASTER_SITES=	http://invisible-mirror.net/archives/lynx/tarballs/ \
		ftp://ftp.invisible-island.net/lynx/tarballs/
PKGNAMESUFFIX=	-current
DISTNAME=	${PORTNAME}${PORTVERSION:S/p/pre./:S/d/dev./}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Console-based web browser (current/development version)

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

CONFLICTS_INSTALL=	lynx-2.8* ja-lynx

USES=		cpe iconv ncurses shebangfix tar:bzip2
WRKSRC=		${WRKDIR}/${DISTNAME}
CPE_VERSION=	${PORTVERSION:C/[pd].+//}
CPE_UPDATE=	${PORTVERSION:E:C/[0-9]+//:S/p/pre./:S/d/dev./}
SHEBANG_FILES=	samples/mailto-form.pl
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${PREFIX}/etc" \
		--with-bzlib --with-zlib \
		--with-mime-libdir=${PREFIX}/etc \
		--with-screen=${NCURSES_IMPL} \
		--enable-default-colors \
		--enable-gzip-help \
		--enable-ipv6 \
		--enable-nested-tables \
		--enable-nsl-fork \
		${ICONV_CONFIGURE_ARGS}

MAKE_FLAGS=	helpdir="${PREFIX}/share/lynx_help" docdir="${DOCSDIR}"
MAKEFILE=	makefile
INSTALL_TARGET=	install-full

DOCSDIR=	${PREFIX}/share/doc/lynx

OPTIONS_DEFINE=	DOCS GNUTLS IDN NLS
OPTIONS_DEFAULT=IDN
OPTIONS_SUB=	yes

GNUTLS_CONFIGURE_ON=	--with-gnutls --without-ssl
GNUTLS_CONFIGURE_OFF=	--with-ssl=${OPENSSLBASE} --without-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES_OFF=	ssl

IDN_CONFIGURE_ENABLE=	idna
IDN_LIB_DEPENDS=	libidn.so:dns/libidn

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
