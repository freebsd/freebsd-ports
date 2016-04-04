# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-MIME-CreateHTML
PORTVERSION=	1.041
CATEGORIES=	mail www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multipart HTML Email builder

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Data-Serializer>=0:devel/p5-Data-Serializer \
		p5-Email-MIME>=0:mail/p5-Email-MIME \
		p5-File-Policy>=0:devel/p5-File-Policy \
		p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
		p5-HTML-TokeParser-Simple>=3.15:www/p5-HTML-TokeParser-Simple \
		p5-Log-Trace>=0:devel/p5-Log-Trace \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Email-Address>=0:mail/p5-Email-Address \
		p5-Email-Send>=0:mail/p5-Email-Send \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-TreeBuilder-XPath>=0:www/p5-HTML-TreeBuilder-XPath \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-Test-Assertions>=0:devel/p5-Test-Assertions \
		p5-common-sense>=0:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
