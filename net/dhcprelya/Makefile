# New ports collection makefile for:	dhcprelya
# Date created:				17 December 2007
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dhcprelya
PORTVERSION=	3.0
CATEGORIES=	net
MASTER_SITES=	http://people.yandex-team.ru/~sem/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Lightweigh DHCP relay agent. Yandex edition

USE_RC_SUBR=	dhcprelya

PORTDOCS=	README

PLIST_FILES=	sbin/${PORTNAME} lib/${PORTNAME}_log_plugin.so

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
