# Ports collection makefile for:  ca-roots
# Date created:			  Sep 5, 2000
# Whom:				  nsayer
#
# $FreeBSD$
#

PORTNAME=	ca-roots
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A list of SSL CA root certificates

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/share/certs
		${INSTALL_DATA} ${FILESDIR}/ca-root.crt ${PREFIX}/share/certs
		${LN} -sf ${PREFIX}/share/certs/ca-root.crt /etc/ssl/cert.pem

.include <bsd.port.mk>
