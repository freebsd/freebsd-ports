# ex:ts=8
# Ports collection makefile for:  translate
# Date created:                   Thu Jun 13, 2002
# Whom:                           Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	translate
PORTVERSION=	1.00
CATEGORIES=	misc
MASTER_SITES=	http://www.freebsdcluster.org/~mich/software/
DISTNAME=	translate

MAINTAINER=	mich@freebsdcluster.org

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
