# Created by: Alex Povolotsky <tarkhil@over.ru>
# $FreeBSD$

PORTNAME=	cadaver
PORTVERSION=	0.23.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/cadaver/ \
		http://www.tcbug.org/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Commandline client for DAV

LIB_DEPENDS=	neon:${PORTSDIR}/www/neon29

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-netrc
ALL_TARGET=	cadaver

MAN1=		cadaver.1
PLIST_FILES=	bin/cadaver

# Neither expat nor libneon are needed at all, but the configure
# script breaks if it can not find the Makefile* in them. Exclude
# them to be sure, a stray .h is not included instead of what's
NO_STAGE=	yes
# found under PREFIX (installed by the neon port):
EXTRACT_AFTER_ARGS=	\
		--exclude '${PORTNAME}-${PORTVERSION}/lib/expat/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/intl/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/neon/*.[ch]' \
		--exclude 'glob.[ch]' --exclude 'mkstemp.[ch]'	\
		--exclude 'tempname.[ch]' --exclude 'basename.[ch]'

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl --with-force-ssl
post-install:
	#
	#
	@${CAT} ${PKGMESSAGE}
	#
	#
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES=		gettext iconv
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE}
LANGS=en@quot es it
.for lang in ${LANGS}
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/cadaver.mo
.endfor
.else
CONFIGURE_ARGS+=--disable-nls \
		--without-libiconv-prefix \
		--without-libintl-prefix
.endif

.include <bsd.port.mk>
