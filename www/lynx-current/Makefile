# Created by: ache
# $FreeBSD$

PORTNAME=	lynx
PORTVERSION=	2.8.9d9
CATEGORIES=	www ipv6
MASTER_SITES=	http://invisible-mirror.net/archives/lynx/tarballs/ \
		ftp://invisible-island.net/lynx/tarballs/
PKGNAMESUFFIX=	-current
DISTNAME=	${PORTNAME}${PORTVERSION:S/p/pre./:S/d/dev./}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Non-graphical, text-based World-Wide Web client

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

CONFLICTS_INSTALL=	lynx-2.8.[0-8].* ja-lynx-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		cpe iconv ncurses shebangfix tar:bzip2
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
CPE_VERSION=	${PORTVERSION:C/[pd].+//}
CPE_UPDATE=	${PORTVERSION:E:C/[0-9]+//:S/p/pre./:S/d/dev./}

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

IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_ENABLE=	idna

post-patch:
	${REINPLACE_CMD} -Ee 's/lynx\.(cfg|lss)\.default/lynx.\1.sample/g' \
		-e '/SYSCONFDIR)\/lynx\.(cfg|lss)$$/d' ${WRKSRC}/makefile.in

.include <bsd.port.mk>
