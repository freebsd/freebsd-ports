# New ports collection makefile for:	p5-Bundle-Sledge
# Date created:		26 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Bundle-Sledge
PORTVERSION=	0.04
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bundle to install all modules used for Sledge

BUILD_DEPENDS=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
		p5-Test-Inline>=0:${PORTSDIR}/devel/p5-Test-Inline \
		p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert \
		p5-Class-Fields>=0:${PORTSDIR}/devel/p5-Class-Fields \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Singleton>=0:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-Class-Trigger>=0:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-HTML-StickyQuery>=0:${PORTSDIR}/www/p5-HTML-StickyQuery \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		ja-p5-Jcode>=0:${PORTSDIR}/japanese/p5-Jcode \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Data-Properties>=0:${PORTSDIR}/devel/p5-Data-Properties \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_APACHE=	20+
PERL_CONFIGURE=	yes

MAN3=		Bundle::Sledge.3

.include <bsd.port.mk>
