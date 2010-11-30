# New ports collection makefile for:	sysutils/pdsh
# Date created:		2010-03-09
# Whom:			Mykola Dzham <i@levsha.me>
#
# $FreeBSD$
#

PORTNAME=	pdsh
PORTVERSION=	2.23
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	i@levsha.me
COMMENT=	Parallel Distributed Shell

LICENSE=	GPLv2

CONFIGURE_ARGS=	--with-ssh
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes

MAN1=		dshbak.1 pdcp.1 pdsh.1
MLINKS=		pdcp.1 rpdcp.1

.include <bsd.port.mk>
