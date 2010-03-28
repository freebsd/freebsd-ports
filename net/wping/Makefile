# New ports collection makefile for:    wping
# Date created:				Apr 9th 2003
# Whom:	      				Michael L. Hostbaek <mich@freebsdcluster.org>
#
# $FreeBSD$
#

PORTNAME=	wping
PORTVERSION=	0.1a
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A Web-based graphical ping log

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_PERL5=	5.8.0+
USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/wping.pl ${PREFIX}/bin/wping
		${INSTALL_DATA} ${WRKSRC}/wping.conf ${PREFIX}/etc/wping.conf.sample

.include <bsd.port.mk>
