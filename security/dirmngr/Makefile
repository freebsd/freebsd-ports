# Created by: michaelnottebrock@gmx.net
# $FreeBSD$

PORTNAME=	dirmngr
PORTVERSION=	1.1.0
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	dirmngr
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Client for managing and downloading certificate revocation lists

LIB_DEPENDS=	libassuan.so:${PORTSDIR}/security/libassuan \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libksba.so:${PORTSDIR}/security/libksba \
		libpth.so:${PORTSDIR}/devel/pth

USES=		gmake iconv
USE_BZIP2=	yes
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
