# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zetaback
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://labs.omniti.com/zetaback/tags/1.0/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Zetaback ZFS backup and recovery management system

USES=		perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf

MAN1=		zetaback.1 zetaback_agent.1

NO_STAGE=	yes
post-install:
	@${TEST} ! -f ${PREFIX}/etc/zetaback.conf && ${CP} ${PREFIX}/etc/zetaback.conf.sample ${PREFIX}/etc/zetaback.conf; ${TRUE}
	@${TEST} ! -f ${PREFIX}/etc/zetaback_agent.conf && ${CP} ${PREFIX}/etc/zetaback_agent.conf.sample ${PREFIX}/etc/zetaback_agent.conf; ${TRUE}

.include <bsd.port.mk>
