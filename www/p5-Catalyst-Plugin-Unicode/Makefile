# Ports collection makefile for:	p5-Catalyst-Plugin-Unicode
# Date created:				Mar 26, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Unicode
PORTVERSION=	0.93
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Unicode aware Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Unicode.3

post-extract:
	@${REINPLACE_CMD} -e '/build_requires/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
