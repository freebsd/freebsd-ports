# New ports collection makefile for:    wping
# Date created:				Apr 9th 2003
# Whom:	      				Michael L. Hostbaek <mich@freebsdcluster.org>
#
# $FreeBSD$
#

PORTNAME=	wping
PORTVERSION=	0.1a
CATEGORIES=	net
MASTER_SITES=	http://www.x-router.com/files/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A Web-based graphical ping log

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/wping.pl ${PREFIX}/bin/wping
		${INSTALL_DATA} ${WRKSRC}/wping.conf ${PREFIX}/etc/wping.conf.sample

.include <bsd.port.pre.mk>

##
## this port requires PERL 5.8.x or later
##
.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
