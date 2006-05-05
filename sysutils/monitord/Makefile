# New ports collection makefile for:	monitord
# Date created:				5 June 2000
# Whom:					walt
#
# $FreeBSD$
#

PORTNAME=	monitord
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.erudition.net/pub/monitord/

MAINTAINER=	walt@erudition.net
COMMENT=	Service that restarts other standalone services

MAN8=		monitord.8

post-patch:
	@${REINPLACE_CMD} -e 's|syslodg|syslogd|' ${WRKSRC}/${MAN8}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/monitord.conf.sample \
		${PREFIX}/etc/monitord.conf.sample

.include <bsd.port.mk>
