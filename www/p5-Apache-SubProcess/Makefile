# New ports collection makefile for:	Apache-SubProcess
# Date created:				25 October 2002
# Whom:					larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	Apache-SubProcess
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Forking and executing subprocesses from mod_perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
