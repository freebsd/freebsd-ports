# New ports collection makefile for:	newpg
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.9.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/gnupg
PKGNAMESUFFIX=	-devel

MAINTAINER=	lofi@freebsd.org
COMMENT=	Prerelease package of GnuPG extensions for GnuPG 2.0

BUILD_DEPENDS=	${LOCALBASE}/lib/libassuan.a:${PORTSDIR}/security/libassuan
LIB_DEPENDS=	gcrypt.12:${PORTSDIR}/security/libgcrypt \
		ksba.13:${PORTSDIR}/security/libksba \
		pth.20:${PORTSDIR}/devel/pth
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		dirmngr:${PORTSDIR}/security/dirmngr

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=# empty
USE_GMAKE=	yes
USE_ICONV=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
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

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
