# Created by: michaelnottebrock@gmx.net
# $FreeBSD$

PORTNAME=	dirmngr
PORTVERSION=	1.1.0
PORTREVISION=	13
CATEGORIES=	security
MASTER_SITES=	GNUPG
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Client for managing and downloading certificate revocation lists

LICENSE=	GPLv2

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libksba.so:security/libksba \
		libpth.so:devel/pth

USES=		gmake iconv tar:bzip2
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
INFO=		dirmngr

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
