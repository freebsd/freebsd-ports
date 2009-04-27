# New ports collection makefile for:	zetaback
# Date created:				Wed Aug 13 21:50:57 PDT 2008
# Whom:					Cy Schubert <cy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zetaback
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://labs.omniti.com/zetaback/tags/1.0/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Zetaback ZFS backup and recovery management system

USE_PERL5_RUN=	YES
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262

MAN1=		zetaback.1 zetaback_agent.1

post-install:
	@${TEST} ! -f ${PREFIX}/etc/zetaback.conf && ${CP} ${PREFIX}/etc/zetaback.conf.sample ${PREFIX}/etc/zetaback.conf; ${TRUE}
	@${TEST} ! -f ${PREFIX}/etc/zetaback_agent.conf && ${CP} ${PREFIX}/etc/zetaback_agent.conf.sample ${PREFIX}/etc/zetaback_agent.conf; ${TRUE}

.include <bsd.port.mk>
