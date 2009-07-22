# New ports collection makefile for:	p5-Net-DAV-Server
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAV-Server
PORTVERSION=	1.29
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Provide a DAV Server

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/File/Find/Rule/Filesys/Virtual.pm:${PORTSDIR}/devel/p5-File-Find-Rule-Filesys-Virtual \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/devel/p5-DateTime-Format-HTTP \
		${SITE_PERL}/HTTP/Headers.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML

PERL_CONFIGURE=	yes

MAN3=		Net::DAV::Server.3

.include <bsd.port.mk>
