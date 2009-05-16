# New ports collection makefile for:	p5-Apache-ConfigParser
# Date created:				24 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-ConfigParser
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Load Apache configuration files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/FnMatch.pm:${PORTSDIR}/devel/p5-File-FnMatch \
		${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node

MAKE_JOBS_SAFE=  yes

MAN3=	Apache::ConfigParser.3 Apache::ConfigParser::Directive.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
