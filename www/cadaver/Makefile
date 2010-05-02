# New ports collection makefile for: cadaver
# Date created:		13 January 2000
# Whom:			Alex Povolotsky <tarkhil@over.ru>
#
# $FreeBSD$
#

PORTNAME=	cadaver
PORTVERSION=	0.23.3
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/cadaver/ \
		http://www.tcbug.org/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Commandline client for DAV

LIB_DEPENDS=	neon:${PORTSDIR}/www/neon29

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-netrc
ALL_TARGET=	cadaver
MAKE_JOBS_SAFE=	yes

MAN1=		cadaver.1
PLIST_FILES=	bin/cadaver

# Neither expat nor libneon are needed at all, but the configure
# script breaks if it can not find the Makefile* in them. Exclude
# them to be sure, a stray .h is not included instead of what's
# found under PREFIX (installed by the neon port):
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/expat/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/intl/*.[ch]' \
		--exclude '${PORTNAME}-${PORTVERSION}/lib/neon/*.[ch]' \
		--exclude 'glob.[ch]' --exclude 'mkstemp.[ch]'	\
		--exclude 'tempname.[ch]' --exclude 'basename.[ch]'

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

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

.if !defined(WITHOUT_NLS)
USE_ICONV=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE} \
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
