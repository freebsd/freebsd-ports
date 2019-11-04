# Created by: ache
# $FreeBSD$

PORTNAME=	lynx
PORTVERSION=	2.9.0d4
CATEGORIES=	www
MASTER_SITES=	http://invisible-mirror.net/archives/lynx/tarballs/ \
		ftp://invisible-island.net/lynx/tarballs/
PKGNAMESUFFIX=	-current
DISTNAME=	${PORTNAME}${PORTVERSION:S/p/pre./:S/d/dev./}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Console-based web browser (current/development version)

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

CONFLICTS_INSTALL=	lynx-2.8.[0-8].* ja-lynx-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		cpe iconv ncurses shebangfix tar:bzip2
SHEBANG_FILES=	samples/mailto-form.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork --with-bzlib --with-zlib \
		--enable-nested-tables --enable-default-colors \
		--enable-addrlist-page \
		--enable-gzip-help \
		--enable-idna \
		--enable-ipv6 \
		--with-mime-libdir=${PREFIX}/etc \
		${ICONV_CONFIGURE_ARG} \
		--with-screen=ncursesw
CPE_VERSION=	${PORTVERSION:C/[pd].+//}
CPE_UPDATE=	${PORTVERSION:E:C/[0-9]+//:S/p/pre./:S/d/dev./}

MAKE_JOBS_UNSAFE=	yes

MAKE_FLAGS=	helpdir="${PREFIX}/share/lynx_help" docdir="${DOCSDIR}" -f
MAKEFILE=	makefile
INSTALL_TARGET=	install-full

DOCSDIR=	${PREFIX}/share/doc/lynx

OPTIONS_DEFINE=	GNUTLS IDN NLS DOCS
OPTIONS_DEFAULT=IDN
OPTIONS_SUB=	yes

IDN_CONFIGURE_ENABLE=	idna
IDN_LIB_DEPENDS=	libidn.so:dns/libidn

GNUTLS_CONFIGURE_ON=	--with-gnutls --without-ssl
GNUTLS_CONFIGURE_OFF=	--with-ssl=${OPENSSLBASE} --without-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES_OFF=	ssl

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
