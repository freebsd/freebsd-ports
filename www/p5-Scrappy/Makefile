# $FreeBSD$

PORTNAME=	Scrappy
PORTVERSION=	0.94112090
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	All Powerful Web Harvester, Spider, Scraper fully automated

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.03:devel/p5-File-ShareDir-Install \
		p5-Array-Unique>=0:devel/p5-Array-Unique \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-File-Util>=0:devel/p5-File-Util \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Moose>=0:devel/p5-Moose \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-String-TT>=0:devel/p5-String-TT \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-Web-Scraper>=0:www/p5-Web-Scraper \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} ${WRKSRC}/perltidy.pl
	${RM} ${WRKSRC}/lib/Scrappy.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Action.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Logger.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Scraper.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Queue.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Session.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Project.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Plugin.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Action/Help.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Action/Generate.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Plugin/RandomProxy.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Project/Document.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Scraper/Control.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Scraper/Parser.pm.bak
	${RM} ${WRKSRC}/lib/Scrappy/Scraper/UserAgent.pm.bak

.include <bsd.port.mk>
