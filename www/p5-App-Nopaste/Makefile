# $FreeBSD$

PORTNAME=	App-Nopaste
PORTVERSION=	0.92
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy access to any pastebin

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Getopt-Long-Descriptive>=0:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	CLIPBOARD GITHUB PASTEBIN
OPTIONS_DEFAULT=CLIPBOARD GITHUB PASTEBIN
CLIPBOARD_DESC=	Support X11 clipboard
GITHUB_DESC=	Support github.com
PASTEBIN_DESC=	Support pastebin.com

USES=		perl5
USE_PERL5=	configure

CONFLICTS=	p5-WebService-NoPaste-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIPBOARD}
BUILD_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
RUN_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
.endif

.if ${PORT_OPTIONS:MGITHUB}
BUILD_DEPENDS+=	p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike
RUN_DEPENDS+=	p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike
.endif

.if ${PORT_OPTIONS:MPASTEBIN}
BUILD_DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create>=0:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
RUN_DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create>=0:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
.endif

.include <bsd.port.mk>
