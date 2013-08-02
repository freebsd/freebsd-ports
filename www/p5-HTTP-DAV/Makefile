# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	HTTP-DAV
PORTVERSION=	0.47
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	WebDAV client library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-DOM>0:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-libwww>=5.48:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		dave.1
MAN3=		HTTP::DAV.3 HTTP::DAV::Lock.3 HTTP::DAV::Resource.3 \
		HTTP::DAV::Response.3 HTTP::DAV::Changes.3

.include <bsd.port.mk>
