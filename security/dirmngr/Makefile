# New ports collection makefile for:	dirmngr
# Date created:		06 Feb 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	dirmngr
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	dirmngr

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A client for managing and downloading certificate revocation lists

BUILD_DEPENDS=	libassuan-1>=1.0.5:${PORTSDIR}/security/libassuan-1
LIB_DEPENDS=	gcrypt.16:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error \
		ksba.17:${PORTSDIR}/security/libksba \
		pth:${PORTSDIR}/devel/pth

USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INFO=		dirmngr
MAN1=		dirmngr-client.1 dirmngr.1

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
