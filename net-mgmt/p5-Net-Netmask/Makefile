# New ports collection makefile for:	p5-Net-Netmask
# Date created:				Jan 28 2000
# Whom:					Wei-chun Chao
#
# $FreeBSD$
#

PORTNAME=	Net-Netmask
PORTVERSION=	1.9008
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Perl module to parse, manipulate and lookup IP network blocks

PERL_CONFIGURE=	yes

MAN3=		Net::Netmask.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
# make PREFIX-clean under perl 5.005_03
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
