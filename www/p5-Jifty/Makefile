# New ports collection makefile for:	www/p5-Jifty
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jifty
PORTVERSION=	1.10214
#PORTREVISION=	0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Jifty -- Just Do It -- Yet another web framework

RUN_DEPENDS=	\
		p5-App-CLI>=0.03:${PORTSDIR}/devel/p5-App-CLI \
		p5-CGI-Cookie-Splitter>=0:${PORTSDIR}/www/p5-CGI-Cookie-Splitter \
		p5-CSS-Squish>=0.05:${PORTSDIR}/textproc/p5-CSS-Squish \
		p5-Cache-Cache>0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Calendar-Simple>0:${PORTSDIR}/devel/p5-Calendar-Simple \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Accessor-Named>=0:${PORTSDIR}/devel/p5-Class-Accessor-Named \
		p5-Class-Container>0:${PORTSDIR}/devel/p5-Class-Container \
		p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Trigger>=0.12:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-Clone>0:${PORTSDIR}/devel/p5-Clone \
		p5-Crypt-CBC>0:${PORTSDIR}/security/p5-Crypt-CBC \
		p5-Crypt-Rijndael>0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-DBD-SQLite>=1.11:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Data-UUID>0:${PORTSDIR}/devel/p5-Data-UUID \
		p5-Date-Manip>0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
		p5-Devel-Cover>0:${PORTSDIR}/devel/p5-Devel-Cover \
		p5-Email-Folder>0:${PORTSDIR}/mail/p5-Email-Folder \
		p5-Email-LocalDelivery>0:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		p5-Email-MIME>0:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-MIME-CreateHTML>0:${PORTSDIR}/mail/p5-Email-MIME-CreateHTML \
		p5-Email-MIME-ContentType>0:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-Email-Send>=2.00:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple>=2.100:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Exporter-Lite>0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-MMagic>0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-File-ShareDir>=0.04:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-HTML-Lint>0:${PORTSDIR}/www/p5-HTML-Lint \
		p5-HTML-Mason>=1.31.0.1:${PORTSDIR}/www/p5-HTML-Mason \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Server-Simple-Recorder>0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Recorder \
		p5-HTTP-Server-Simple>=0.26:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Hook-LexWrap>0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-IPC-PubSub>=0.23:${PORTSDIR}/devel/p5-IPC-PubSub \
		p5-IPC-Run3>0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Jifty-DBI>=0.57:${PORTSDIR}/databases/p5-Jifty-DBI \
		p5-Locale-Maketext-Lexicon>=0.60:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Log-Log4perl>=1.04:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Module-Install>=0.50:${PORTSDIR}/devel/p5-Module-Install \
		p5-Module-Refresh>=0.09:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Module-ScanDeps>0:${PORTSDIR}/devel/p5-Module-ScanDeps \
		p5-Net-Server>0:${PORTSDIR}/net/p5-Net-Server \
		p5-Object-Declare>=0.13:${PORTSDIR}/devel/p5-Object-Declare \
		p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-PerlIO-gzip>=0:${PORTSDIR}/archivers/p5-PerlIO-gzip \
		p5-Pod-Simple>0:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-Scalar-Defer>=0.10:${PORTSDIR}/devel/p5-Scalar-Defer \
		p5-SQL-ReservedWords>0:${PORTSDIR}/databases/p5-SQL-ReservedWords \
		p5-String-Koremutake>0:${PORTSDIR}/textproc/p5-String-Koremutake \
		p5-SUPER>=0:${PORTSDIR}/devel/p5-SUPER \
		p5-Template-Declare>=0.26:${PORTSDIR}/textproc/p5-Template-Declare \
		p5-Test-Base>=0.44:${PORTSDIR}/devel/p5-Test-Base \
		p5-Test-HTTP-Server-Simple>=0.02:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		p5-Test-Log4perl>0:${PORTSDIR}/devel/p5-Test-Log4perl \
		p5-Test-MockModule>=0.05:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Test-MockObject>=1.07:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-Pod-Coverage>0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-WWW-Declare>=0:${PORTSDIR}/devel/p5-Test-WWW-Declare \
		p5-Test-WWW-Mechanize>=1.04:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-Test-WWW-Selenium>=0:${PORTSDIR}/devel/p5-Test-WWW-Selenium \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.30:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-Writer>0.601:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-XPath>0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-YAML>=0.35:${PORTSDIR}/textproc/p5-YAML \
		p5-YAML-Syck>=0.71:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-version>0:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

.include "Makefile.man"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

post-patch:
	${REINPLACE_CMD} -e '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
