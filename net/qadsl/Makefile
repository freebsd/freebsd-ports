# New ports collection makefile for:	qadsl
# Date created:				13 December 2001
# Whom:					Arne Lundberg <arlu@telia.com>
#
# $FreeBSD$
#

PORTNAME=	qadsl
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	http://kuba.unix.se/code/
DISTNAME=	qadsl-final-${PORTVERSION}

MAINTAINER=	arlu@telia.com
COMMENT=	Auto login/Keep-alive for Telia AB ADSL and COMHEM Cable internet

MAN8=		qadsl.8
MANCOMPRESSED=	yes

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
