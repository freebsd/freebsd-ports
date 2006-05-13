# New ports collection makefile for:	newpg
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.9.20
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/gnupg
PKGNAMESUFFIX=	-devel

MAINTAINER=	lofi@freebsd.org
COMMENT=	Prerelease package of GnuPG extensions for GnuPG 2.0

BUILD_DEPENDS=	${LOCALBASE}/lib/libassuan.a:${PORTSDIR}/security/libassuan
LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt \
		ksba.15:${PORTSDIR}/security/libksba \
		pth.20:${PORTSDIR}/devel/pth \
		usb-0.1:${PORTSDIR}/devel/libusb
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		dirmngr:${PORTSDIR}/security/dirmngr

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=# empty
USE_GMAKE=	yes
USE_ICONV=	yes
INSTALLS_SHLIB=	yes
INFO=		gnupg

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include/pth" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib/pth"

.include <bsd.port.pre.mk>

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
