# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Sledge-Plugin-HTML2HDML
PORTVERSION=	0.01
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2451
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that invokes html2hdml for EZweb WAP/1.0 clients

DEPRECATED=	depends on mod_perl 1 which is gone
EXPIRATION_DATE=	2012-11-28

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS} \
		html2hdml:${PORTSDIR}/www/html2hdml

PM_DEPENDS=	p5-Sledge>=0:${PORTSDIR}/www/p5-Sledge
PM_DEPENDS+=	p5-HTTP-MobileAgent>=0:${PORTSDIR}/www/p5-HTTP-MobileAgent

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::HTML2HDML.3

.include <bsd.port.mk>
