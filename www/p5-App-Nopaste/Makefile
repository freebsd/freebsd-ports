# $FreeBSD$

PORTNAME=	App-Nopaste
PORTVERSION=	1.004
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy access to any pastebin

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Browser-Open>=0:www/p5-Browser-Open \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Getopt-Long-Descriptive>=0:devel/p5-Getopt-Long-Descriptive \
		p5-JSON>=0:converters/p5-JSON \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-libwww>=0:www/p5-libwww

CONFLICTS=	p5-WebService-NoPaste-[0-9]*

OPTIONS_DEFINE=	CLIPBOARD GITHUB PASTEBIN
OPTIONS_DEFAULT=CLIPBOARD GITHUB PASTEBIN
CLIPBOARD_DESC=	Support X11 clipboard
GITHUB_DESC=	Support github.com
PASTEBIN_DESC=	Support pastebin.com

USES=		perl5
USE_PERL5=	configure

CLIPBOARD_BUILD_DEPENDS=p5-Clipboard>=0:x11/p5-Clipboard
CLIPBOARD_RUN_DEPENDS=	p5-Clipboard>=0:x11/p5-Clipboard
GITHUB_BUILD_DEPENDS=	p5-Config-GitLike>=0:devel/p5-Config-GitLike
GITHUB_RUN_DEPENDS=	p5-Config-GitLike>=0:devel/p5-Config-GitLike
PASTEBIN_BUILD_DEPENDS=	p5-WWW-Pastebin-PastebinCom-Create>=0:www/p5-WWW-Pastebin-PastebinCom-Create
PASTEBIN_RUN_DEPENDS=	p5-WWW-Pastebin-PastebinCom-Create>=0:www/p5-WWW-Pastebin-PastebinCom-Create

.include <bsd.port.mk>
