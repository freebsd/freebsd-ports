# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Jabber
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	jabber

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::Jabber provides Perl Developer access to the Jabber protocol

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-XMPP>=0:net-im/p5-Net-XMPP

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
