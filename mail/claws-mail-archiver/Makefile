# New ports collection makefile for:	sylpheed-claws-mail-archiver
# Date created:		28 june 2008
# Whom:			Martin Wilke
#
# $FreeBSD$
#

PORTNAME=	archiver
PORTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	archive-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	mail archiver plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.8:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.8:${PORTSDIR}/mail/claws-mail

LICENSE=	GPLv3

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
