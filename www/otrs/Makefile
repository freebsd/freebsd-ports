# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	otrs
PORTVERSION=	6.0.6
CATEGORIES=	www

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Open Ticket Request System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-DBI>=0:databases/p5-DBI \
		p5-Crypt-Eksblowfish>=0:security/p5-Crypt-Eksblowfish \
		p5-Crypt-PasswdMD5>=0:security/p5-Crypt-PasswdMD5 \
		p5-MIME-Tools>=5.427:mail/p5-MIME-Tools \
		p5-libwww>=0:www/p5-libwww \
		p5-Net-DNS>=0.66:dns/p5-Net-DNS \
		p5-CSS-Minifier-XS>=0:textproc/p5-CSS-Minifier-XS \
		p5-JavaScript-Minifier-XS>=0:textproc/p5-JavaScript-Minifier-XS \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Sys-Hostname-Long>=0:sysutils/p5-Sys-Hostname-Long \
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-IO-Interactive>=0:devel/p5-IO-Interactive \
		p5-Email-Valid>=0:mail/p5-Email-Valid \
		p5-JSON>=0:converters/p5-JSON \
		p5-YAML>=0:textproc/p5-YAML \
		p5-Date-Pcalc>=0:devel/p5-Date-Pcalc \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-XML-FeedPP>=0:textproc/p5-XML-FeedPP \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML \
		p5-JavaScript-Minifier>=0:textproc/p5-JavaScript-Minifier \
		p5-CSS-Minifier>=0:textproc/p5-CSS-Minifier \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-Mozilla-CA>=0:www/p5-Mozilla-CA \
		p5-CGI>=0:www/p5-CGI \
		p5-Lingua-Translit>=0:devel/p5-Lingua-Translit \
		p5-Pod-Strip>=0:textproc/p5-Pod-Strip \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe shebangfix perl5 tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	OTRS
GH_TAGNAME=	51cbe50

SHEBANG_FILES=	bin/cgi-bin/*.pl bin/cgi-bin/app.psgi bin/fcgi-bin/*.pl bin/*.pl \
		scripts/tools/*.pl scripts/*.pl

OPTIONS_DEFINE=		MYSQL PGSQL REPORTS SMTP POP3 IMAP LDAP PDF \
			GNUPG APACHE SSL
OPTIONS_DEFAULT=	MYSQL REPORTS SMTP POP3 IMAP PDF ASPELL APACHE \
			SSL
OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL ISPELL

IMAP_DESC=		Fetch email via IMAP
POP3_DESC=		Fetch email via POP3
SMTP_DESC=		Send email via SMTP
REPORTS_DESC=		Reports support
APACHE_DESC=		Apache and www/mod_perl2 support

OTRSDIR=	${PREFIX}/otrs
USERS=		${PORTNAME}
GROUPS=		${USERS} www

SUB_FILES=	pkg-message
SUB_LIST=	OTRS_USER=${USERS} OTRS_GROUP=${USERS} WWWOWN=${WWWOWN}
NO_ARCH=	YES

ROOT_DIRS_LIST=	Kernel bin scripts
BIN_DIRS_LIST=	"" cgi-bin fcgi-bin
PM_DIRS_LIST=	Kernel Kernel/Config Kernel/Config/Files Kernel/Language \
		Modules Kernel/Output/HTML Kernel/Output/HTML/Lite \
		Kernel/Output/HTML/Standard System System/Auth System/AuthSession \
		System/Crypt System/CustomerAuth System/CustomerUser \
		System/CustomerUser/ System/

SCRIPTS_DIRS_LIST=	"" database test tools DBUpdateTo6
CRON_SCRIPTS=	${STAGEDIR}${OTRSDIR}/var/cron/
CLEAN_FILES=	scripts/suse* scripts/redhat* \
		var/httpd/htdocs/js/thirdparty/ckeditor-4.0/_source \
		var/httpd/htdocs/skins/Agent/*/img/source

PLIST_SUB=	VER_CKEDITOR="4.7.0" OTRS_USER=${USERS} WWWOWN=${WWWOWN}

PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PGSQL_USES=		pgsql

MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay

APACHE_RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=2.0.5:www/mod_perl2 \
			p5-Apache-DBI>0:www/p5-Apache-DBI
APACHE_USES=		apache:run,2.2+

REPORTS_RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD \
			p5-GD-Graph>=0:graphics/p5-GD-Graph \
			p5-GD-TextUtil>=0:graphics/p5-GD-TextUtil

SMTP_RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
			p5-Net-SSLGlue>=0:security/p5-Net-SSLGlue

POP3_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
			p5-Net-SSLGlue>=0:security/p5-Net-SSLGlue

IMAP_RUN_DEPENDS=	p5-Mail-IMAPClient>=0:mail/p5-Mail-IMAPClient \
			p5-Net-IMAP-Simple>=0:mail/p5-Net-IMAP-Simple

LDAP_RUN_DEPENDS=	p5-perl-ldap>=0:net/p5-perl-ldap

PDF_RUN_DEPENDS=	p5-PDF-API2>=0.57:textproc/p5-PDF-API2

ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell

ASPELL_RUN_DEPENDS=	aspell:textproc/aspell

GNUPG_RUN_DEPENDS=	gpg:security/gnupg1

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | \
		${XARGS} ${REINPLACE_CMD} -i '' \
			-e 's|Digest::SHA::PurePerl|Digest::SHA|g'
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${RM} -r ${WRKSRC}/Kernel/cpan-lib/ \
		${CLEAN_FILES:S!^!${WRKSRC}/!}

do-build:
	@${FIND} ${WRKSRC}/Kernel -type d | ${XARGS} ${CHMOD} 0755
	@${FIND} ${WRKSRC}/Kernel -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/opt/=${PREFIX}/=g;s=wwwrun=${WWWOWN}=g;"

do-build-ISPELL-on:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/ispell=g"
do-build-ASPELL-on:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/ispell=${PREFIX}/bin/aspell=g"
do-build-GNUPG-on:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${SED} -i '' \
		-e "s=/usr/bin/gpg=${PREFIX}/bin/gpg=g"

do-install:
.for D in ${ROOT_DIRS_LIST:S!^!${OTRSDIR}/!} ${BIN_DIRS_LIST:S!^!${OTRSDIR}/bin/!} ${SCRIPTS_DIRS_LIST:S!^!${OTRSDIR}/scripts/!}
	${MKDIR} ${STAGEDIR}${D}
.endfor
	${INSTALL_DATA} ${WRKSRC}/.*.dist ${STAGEDIR}${OTRSDIR}/
	${INSTALL_DATA} ${WRKSRC}/RELEASE ${STAGEDIR}${OTRSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${OTRSDIR}/
.for D in ${BIN_DIRS_LIST}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${D}/*.* ${STAGEDIR}${OTRSDIR}/bin/${D}/
.endfor
	(cd ${WRKSRC} && ${PAX} -r -w Kernel var ${STAGEDIR}${OTRSDIR})
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.[ps][lh] ${STAGEDIR}${OTRSDIR}/scripts/
	${INSTALL_DATA} ${WRKSRC}/scripts/apache* \
		${WRKSRC}/scripts/*.[pl][pm] ${STAGEDIR}${OTRSDIR}/scripts/
	${INSTALL_DATA} ${WRKSRC}/scripts/database/*.* ${STAGEDIR}${OTRSDIR}/scripts/database/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/test/*.t ${STAGEDIR}${OTRSDIR}/scripts/test/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/tools/*.pl ${STAGEDIR}${OTRSDIR}/scripts/tools/
	${FIND} ${CRON_SCRIPTS} -type f -name *.dist | ${SED} -e "p;s/\.dist//" | ${XARGS} -n2 ${MV}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/var/article
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/var/httpd/htdocs/js/js-cache/
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/var/tmp

# otrs.SetPermissions.pl does not work in stage environment due to missing otrs user
#post-install:
#	cd ${STAGEDIR}/${OTRSDIR} && ${PERL} ./bin/otrs.SetPermissions.pl \
#	--web-group=${WWWOWN} \
#	--otrs-user=${PORTNAME} \
#	--admin-group=wheel  ${STAGEDIR}${OTRSDIR}

.include <bsd.port.post.mk>
