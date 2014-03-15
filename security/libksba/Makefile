# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.3.0
CATEGORIES=	security
MASTER_SITES=	GNUPG/${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

LICENSE=	GPLv2 GPLv3 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	libgpg-error>=1.10:${PORTSDIR}/security/libgpg-error
LIB_DEPENDS=	libgpg-error.so:${PORTSDIR}/security/libgpg-error

CONFIGURE_ARGS=	--enable-static
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		perl5 tar:bzip2

INFO=		ksba

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
