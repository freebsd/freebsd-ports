# New ports collection makefile for:	p5-Ark
# Date created:		06 Jun 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Ark
PORTVERSION=	0.1.r1
CATEGORIES=	www perl5
MASTER_SITES=	http://cloud.github.com/downloads/typester/ark-perl/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMEPREFIX=	p5-
DISTNAME=	Ark-0.001000_001

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl web application framework

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
	p5-Class-Method-Modifiers-Fast>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers-Fast \
	p5-Data-UUID>0:${PORTSDIR}/devel/p5-Data-UUID \
	p5-Data-Util>0:${PORTSDIR}/devel/p5-Data-Util \
	p5-Devel-StackTrace>0:${PORTSDIR}/devel/p5-Devel-StackTrace \
	p5-Digest-SHA1>0:${PORTSDIR}/security/p5-Digest-SHA1 \
	p5-FindBin-libs>0:${PORTSDIR}/devel/p5-FindBin-libs \
	p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-HTTP-Engine>=0.1.8:${PORTSDIR}/www/p5-HTTP-Engine \
	p5-HTTP-Engine-Middleware>=0.13:${PORTSDIR}/www/p5-HTTP-Engine-Middleware \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-Module-Pluggable>0:${PORTSDIR}/devel/p5-Module-Pluggable \
	p5-Module-Setup>0:${PORTSDIR}/devel/p5-Module-Setup \
	p5-Mouse>=0.21:${PORTSDIR}/devel/p5-Mouse \
	p5-MouseX-Types-Path-Class>0:${PORTSDIR}/devel/p5-MouseX-Types-Path-Class \
	p5-Path-Class>=0.16:${PORTSDIR}/devel/p5-Path-Class \
	p5-Text-SimpleTable>=0.05:${PORTSDIR}/textproc/p5-Text-SimpleTable \
	p5-URI>0:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	5.8.1+

MAN3=	Ark::Command.3 \
	Ark::Command::Controller.3 \
	Ark::Command::Model.3 \
	Ark::Command::Newapp.3 \
	Ark::Command::Server.3 \
	Ark::Command::View.3

.include <bsd.port.mk>
