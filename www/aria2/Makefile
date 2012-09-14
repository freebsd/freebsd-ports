# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
PORTVERSION=	1.15.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet another download tool

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS NLS SQLITE
OPTIONS_DEFAULT=SQLITE

CONFIGURE_ARGS=	--enable-bittorrent --disable-epoll --enable-metalink --enable-threads=pth \
		--with-libz --with-libxml2 --with-openssl \
		--without-gnutls --without-libcares
CONFIGURE_ENV=	OPENSSL_CFLAGS=-I${OPENSSLINC} OPENSSL_LIBS="-L${OPENSSLLIB} -lssl" \
		ZLIB_CFLAGS=-I${INCLUDEDIR} ZLIB_LIBS="-L${LIBDIR} -lz"
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack libxml2
USE_OPENSSL=	yes

MAN1=		aria2c.1
MANLANG=	"" ru
PLIST_FILES=	bin/aria2c

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	%%DOCSDIR%%/README \
		%%DOCSDIR%%/README.html \
		%%DOCSDIR%%/README.rst \
		%%DOCSDIR%%/bash_completion/README.txt \
		%%DOCSDIR%%/bash_completion/aria2c \
		%%DOCSDIR%%/xmlrpc/README.txt \
		%%DOCSDIR%%/xmlrpc/aria2mon \
		%%DOCSDIR%%/xmlrpc/aria2rpc
PLIST_DIRS=	%%DOCSDIR%%/xmlrpc \
		%%DOCSDIR%%/bash_completion \
		%%DOCSDIR%%
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE}
USE_GETTEXT=	yes
LANGS=		ar bg ca da de el en@boldquot en@quot es fi fr he hu id it ja \
		ko nl nn pl pt pt_BR ru sk sr sv th tr uk vi zh_CN zh_TW
PLIST_FILES+=	${LANGS:S|^|share/locale/|:S|$|/LC_MESSAGES/aria2.mo|}
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=--with-sqlite3
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=--without-sqlite3
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
.else
	@${REINPLACE_CMD} -e 's|\(install-exec-am\) install-data-am|\1|' ${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not install on powerpc-9
.endif

.include <bsd.port.post.mk>
