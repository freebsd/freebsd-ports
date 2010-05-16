# New ports collection makefile for:	sylpheed-claws-mail-archiver
# Date created:		28 june 2008
# Whom:			Martin Wilke
#
# $FreeBSD$
#

PORTNAME=	archiver
PORTVERSION=	0.6.7
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	archive-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	mail archiver plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262

.include <bsd.port.mk>
