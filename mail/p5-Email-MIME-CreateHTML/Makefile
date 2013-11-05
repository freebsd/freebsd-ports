# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-MIME-CreateHTML
PORTVERSION=	1.030
PORTREVISION=	1
CATEGORIES=	mail www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multipart HTML Email builder

BUILD_DEPENDS=	p5-File-Policy>=0:${PORTSDIR}/devel/p5-File-Policy \
		p5-Data-Serializer>0:${PORTSDIR}/devel/p5-Data-Serializer \
		p5-Email-MIME>0:${PORTSDIR}/mail/p5-Email-MIME \
		p5-HTML-Tagset>0:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-TokeParser-Simple>0:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-Log-Trace>0:${PORTSDIR}/devel/p5-Log-Trace \
		p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Assertions>0:${PORTSDIR}/devel/p5-Test-Assertions

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
