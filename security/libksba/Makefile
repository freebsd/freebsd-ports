# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

BUILD_DEPENDS+=	libgpg-error>=1.10:${PORTSDIR}/security/libgpg-error
LIB_DEPENDS+=	gpg-error:${PORTSDIR}/security/libgpg-error

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-static
USE_LDCONFIG=	yes
USES=		perl5
USE_PERL5=	build

INFO=		ksba

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

NO_STAGE=	yes
.include <bsd.port.mk>
