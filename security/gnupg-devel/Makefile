# New ports collection makefile for:	newpg
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	newpg
PORTVERSION=	0.9.4
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/aegypten

MAINTAINER=	lofi@freebsd.org
COMMENT=	Prerelease package of GnuPG extensions for GnuPG 2.0

LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt \
		iconv.3:${PORTSDIR}/converters/libiconv \
		ksba.7:${PORTSDIR}/security/libksba \
		pth.20:${PORTSDIR}/devel/pth
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		pinentry-curses:${PORTSDIR}/security/pinentry \
		dirmngr:${PORTSDIR}/security/dirmngr
		
USE_AUTOCONF_VER=253
USE_LIBTOOL=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=--with-included-gettext=no
INFO=		gnupg

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
