# New ports collection makefile for:	sylpheed-claws-mail-archiver
# Date created:		28 june 2008
# Whom:			Martin Wilke
#
# $FreeBSD$
#

PORTNAME=	archiver
PORTVERSION=	0.6.12
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	archive-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	mail archiver plugin for claws-mail

LICENSE=	GPLv3

BUILD_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
