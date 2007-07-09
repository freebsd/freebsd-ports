# New ports collection makefile for:	zxid
# Date created:		2007-07-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	zxid
PORTVERSION=	0.17
CATEGORIES=	security www
MASTER_SITES=	http://zxid.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	Open Source IdM for the Masses - SAML SSO

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

MAKE_ARGS+=	CC="${CC}" CURL_ROOT="${LOCALBASE}" LD="${CC}" \
		PREFIX="${PREFIX}" OPENSSL_ROOT="${OPENSSLBASE}"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

.include <bsd.port.mk>
