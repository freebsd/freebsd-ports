# New ports collection makefile for:	dirmngr
# Date created:		06 Feb 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	dirmngr
PORTVERSION=	1.1.0
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	dirmngr
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A client for managing and downloading certificate revocation lists

LIB_DEPENDS=	assuan.0:${PORTSDIR}/security/libassuan \
		gcrypt.17:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error \
		ksba.18:${PORTSDIR}/security/libksba \
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

OPTIONS=	NLS "National Language Support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.post.mk>
