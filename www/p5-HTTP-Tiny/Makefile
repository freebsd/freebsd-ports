# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Tiny
PORTVERSION=	0.024
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A small, simple, correct HTTP/1.1 client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	HTTPS
OPTIONS_DEFAULT=HTTPS

PERL_CONFIGURE=	yes

MAN3=		HTTP::Tiny.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTPS}
BUILD_DEPENDS+=	p5-Net-SSLeay>=1.49:${PORTSDIR}/security/p5-Net-SSLeay
		p5-Mozilla-CA>=20120823:${PORTSDIR}/www/p5-Mozilla-CA
RUN_DEPENDS+=	p5-Net-SSLeay>=1.49:${PORTSDIR}/security/p5-Net-SSLeay
		p5-Mozilla-CA>=20120823:${PORTSDIR}/www/p5-Mozilla-CA
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-IPC-Cmd>=0:${PORTSDIR}/devel/p5-IPC-Cmd
RUN_DEPENDS+=	p5-IPC-Cmd>=0:${PORTSDIR}/devel/p5-IPC-Cmd
.endif

.include <bsd.port.post.mk>
