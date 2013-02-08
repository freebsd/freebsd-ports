# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	MogileFS-Client
PORTVERSION=	1.16
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Client library for the MogileFS distributed file system

BUILD_DEPENDS=	p5-IO-stringy>=2.102:${PORTSDIR}/devel/p5-IO-stringy \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-IO-stringy>=2.102:${PORTSDIR}/devel/p5-IO-stringy \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		MogileFS::Client.3

.include <bsd.port.mk>
