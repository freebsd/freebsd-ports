# New ports collection makefile for:	aria2
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2
PORTVERSION=	1.9.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Yet another download tool

CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --with-libxml2 \
		--without-gnutls --with-openssl --with-openssl-prefix=/usr \
		--without-libcares --with-libz --enable-bittorrent \
		--enable-metalink --disable-epoll --enable-threads=pth

USE_BZIP2=	yes
USE_GNOME=	gnomehack libxml2
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

.ifdef WITHOUT_NLS
CONFIGURE_ARGS+=	--disable-nls
.else
LINGUAS=	bg ca da de el en@boldquot en@quot es fi fr he hu id it ja \
		nl nn pl pt pt_BR ru sk sr sv th tr uk vi zh_CN zh_TW
.endif

PLIST_FILES=	bin/aria2c \
		${LINGUAS:S|^|share/locale/|:S|$|/LC_MESSAGES/aria2.mo|} \
		share/doc/aria2/README \
		share/doc/aria2/README.html \
		share/doc/aria2/aria2c.1.html \
		share/doc/aria2/xmlrpc/aria2mon \
		share/doc/aria2/xmlrpc/aria2rpc \
		share/doc/aria2/xmlrpc/README.txt

PLIST_DIRS=	share/doc/aria2/xmlrpc \
		share/doc/aria2

MAN1=		aria2c.1

OPTIONS=	SQLITE "Support for Firefox cookies" Off

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=	--with-sqlite3
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if ${OSVERSION} < 700000
BROKEN=		Does not compile on FreeBSD 6.X
.endif

.include <bsd.port.post.mk>
