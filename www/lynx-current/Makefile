# Created by: ache
# $FreeBSD$

PORTNAME=	lynx
PORTVERSION=	2.8.8p5
PORTREVISION=	1
PKGNAMESUFFIX=	-current
CATEGORIES=	www ipv6
MASTER_SITES=	http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}${PORTVERSION:S/p/pre./}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Non-graphical, text-based World-Wide Web client

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS_INSTALL=	lynx-2.8.[0-7].* ja-lynx-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/./-/g:C/p.*//}
USES=		iconv shebangfix tar:bzip2
USE_OPENSSL=	yes
SHEBANG_FILES=	samples/mailto-form.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --with-bzlib \
		--enable-nested-tables --enable-default-colors \
		--enable-addrlist-page \
		--enable-gzip-help \
		--enable-idna \
		--enable-ipv6 \
		--with-mime-libdir=${PREFIX}/etc \
		${ICONV_CONFIGURE_ARG} \
		--with-screen=ncursesw \
		--with-ssl=${OPENSSLBASE}

MAKE_JOBS_UNSAFE=	yes

MAKE_FLAGS=	helpdir=${L_HELP} docdir=${L_DOC} -f
MAKEFILE=	makefile
INSTALL_TARGET=	install-full

L_LIB=		${PREFIX}/etc
L_DOC=		${PREFIX}/share/doc/lynx
L_HELP=		${PREFIX}/share/lynx_help
DOCSDIR=	${L_DOC}

OPTIONS_DEFINE=	IDN NLS DOCS
OPTIONS_DEFAULT=IDN NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IDN_CONFIGURE_ENABLE=	idna

.include <bsd.port.mk>
