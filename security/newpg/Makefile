# New ports collection makefile for:	newpg
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	newpg
PORTVERSION=	0.9.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/aegypten/

MAINTAINER=	michaelnottebrock@gmx.net

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt \
		iconv.3:${PORTSDIR}/converters/libiconv \
		intl.4:${PORTSDIR}/devel/gettext \
		ksba.7:${PORTSDIR}/security/libksba \
		pth.14:${PORTSDIR}/devel/pth
RUN_DEPENDS=	pinentry-curses:${PORTSDIR}/security/pinentry

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-included-gettext=no

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/opensc-config)
WITH_OPENSC=	yes
.endif

.if defined(WITH_OPENSC)
BUILD_DEPENDS+=	opensc-config:${PORTSDIR}/security/opensc
PLIST_SUB+=	WITH_OPENSC=""
.else
CONFIGURE_ARGS+=	--disable-scdaemon
PLIST_SUB+=	WITH_OPENSC="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	cd ${WRKSRC}; autoconf

.include <bsd.port.post.mk>
