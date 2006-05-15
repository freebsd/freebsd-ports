# New ports collection makefile for:	www/p5-Jifty
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jifty
PORTVERSION=	0.60507
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Jifty
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Jifty -- Just Do It -- Yet another web framework

BUILD_DEPENDS=	\
		p5-App-CLI>=0.03:${PORTSDIR}/devel/p5-App-CLI \
		p5-CGI.pm>0:${PORTSDIR}/www/p5-CGI.pm \
		p5-Cache-Cache>0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Calendar-Simple>0:${PORTSDIR}/devel/p5-Calendar-Simple \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Container>0:${PORTSDIR}/devel/p5-Class-Container \
		p5-Clone>0:${PORTSDIR}/devel/p5-Clone \
		p5-Compress-Zlib>0:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-DBD-SQLite>=1.11:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Date-Manip>0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
		p5-Email-Folder>0:${PORTSDIR}/mail/p5-Email-Folder \
		p5-Email-LocalDelivery>0:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		p5-Email-Send>=2.00:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple-Creator>0:${PORTSDIR}/mail/p5-Email-Simple-Creator \
		p5-Email-Simple>0:${PORTSDIR}/mail/p5-Email-Simple \
		p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-MMagic>0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-HTML-Lint>0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-HTML-Mason>=1.31.0.1:${PORTSDIR}/www/p5-HTML-Mason \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Server-Simple-Recorder>0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Recorder \
		p5-HTTP-Server-Simple>=0.10:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Hook-LexWrap>0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-Jifty-DBI>=0.16:${PORTSDIR}/databases/p5-Jifty-DBI \
		p5-Locale-Maketext-Lexicon>=0.60:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Module-CoreList>0:${PORTSDIR}/devel/p5-Module-CoreList \
		p5-Module-Install>=0.50:${PORTSDIR}/devel/p5-Module-Install \
		p5-Module-Pluggable>=2.95:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Module-Refresh>=0.09:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Pod-Simple>0:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-String-Koremutake>0:${PORTSDIR}/textproc/p5-String-Koremutake \
		p5-Test-Base>=0.44:${PORTSDIR}/devel/p5-Test-Base \
		p5-Test-HTTP-Server-Simple>=0.02:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		p5-Test-Pod-Coverage>0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-WWW-Mechanize>0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.12:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-XML-Writer>0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-XPath>0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-YAML-Syck>=0.44:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-version>0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
IGNORE=		requires perl 5.8.3 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
