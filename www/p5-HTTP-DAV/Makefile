# New ports collection makefile for:	HTTP-DAV
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-DAV
PORTVERSION=	0.31
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1PREFIX=	${PREFIX}
MAN1=		dave.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTTP::DAV.3 HTTP::DAV::Lock.3 HTTP::DAV::Resource.3 \
		HTTP::DAV::Response.3

.include <bsd.port.mk>
