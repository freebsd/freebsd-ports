# New ports collection makefile for:   rt3
# Date created:        28 November 2002
# Whom:                autrijus
#
# $FreeBSD$
#

PORTNAME=	rt3
PORTVERSION?=	3.0.4
CATEGORIES=	www
MASTER_SITES?=	http://www.fsck.com/pub/rt/release/ \
		http://www.fsck.com/pub/rt/devel/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/release/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/devel/
DISTFILES?=	rt-${PORTVERSION:S/./-/g}.tar.gz

MAINTAINER=	autrijus@autrijus.org
COMMENT?=	RT is an industrial-grade ticketing system written in Perl

BUILD_DEPENDS+=	${APXS}:${APACHE_PORT} \
		${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/Cache/Cache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/CGI/Cookie.pm:${PORTSDIR}/www/p5-CGI.pm \
		${ARCH_PERL}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/DBIx/SearchBuilder.pm:${PORTSDIR}/databases/p5-DBIx-SearchBuilder \
		${ARCH_PERL}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${ARCH_PERL}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext \
		${SITE_PERL}/Locale/Maketext/Fuzzy.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Fuzzy \
		${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${ARCH_PERL}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${ARCH_PERL}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${ARCH_PERL}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Text/Autoformat.pm:${PORTSDIR}/textproc/p5-Text-Autoformat \
		${SITE_PERL}/Text/Quoted.pm:${PORTSDIR}/textproc/p5-Text-Quoted \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/Text/Wrapper.pm:${PORTSDIR}/textproc/p5-Text-Wrapper \
		${ARCH_PERL}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC?=	${WRKDIR}/rt-${PORTVERSION:S/./-/g}
HAS_CONFIGURE=	yes
NO_BUILD=	yes
NO_PACKAGE=	Executes scripts in post-install phase

CONFIGURE_ARGS=	--prefix=${RT_PATH} \
		--enable-layout=${LAYOUT} \
		--with-web-user=${WEB_USER} \
		--with-web-group=${WEB_GROUP} \
		--with-libs-group=${LIBS_GROUP} \
		--with-db-host=${DB_HOST} \
		--with-db-port=${DB_PORT} \
		--with-db-type=${DB_TYPE} \
		--with-db-dba=${DB_DBA_USER}

.if defined(WITH_FASTCGI)
APACHE_PORT?=	${PORTSDIR}/www/apache13
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		${ARCH_PERL}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
DEPENDS_ARGS+=	WITHOUT_MODPERL=yes
.else
BUILD_DEPENDS+=	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI
.if defined(WITH_APACHE2)
APACHE_PORT?=	${PORTSDIR}/www/apache2
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
DEPENDS_ARGS+=	WITHOUT_MODPERL=yes
DEPENDS_ARGS+=	WITH_MODPERL2=yes
.else
APACHE_PORT?=	${PORTSDIR}/www/apache13
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
.endif
.endif

APXS?=		${LOCALBASE}/sbin/apxs

DB_TYPE?=	mysql

.if ${DB_TYPE} == "Pg"
BUILD_DEPENDS+=	${LOCALBASE}/bin/psql:${PORTSDIR}/databases/postgresql7 \
		${ARCH_PERL}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.else
DB_TYPE=	mysql
BUILD_DEPENDS+=	${LOCALBASE}/bin/mysql_config:${PORTSDIR}/databases/mysql40-server
.endif

SITE_PERL:=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}/
USE_PERL5=	yes
RT_PATH?=	${PREFIX}/rt3
LAYOUT?=	RT3

DB_DBA_USER?=	root
DB_HOST?=	localhost
DB_DBA_PASSWORD?=

WEB_USER?=	www
WEB_GROUP?=	www
LIBS_GROUP?=	wheel

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    Pg for postgresql, mysql for MySQL (mysql)"
	@${ECHO} "      DB_HOST=hostname                The database host (localhost)"
	@${ECHO} "      DB_PORT=port                    The database port"
	@${ECHO} "      DB_DBA_USER=password            Name of database administrator (root)"
	@${ECHO} "      DB_DBA_PASSWORD=password        Password of database administrator"
	@${ECHO} "      WITH_FASTCGI                    Use FastCGI instead of mod_perl"
	@${ECHO} "      WITH_APACHE2                    Use Apache2 as the web server"
	@${ECHO} "      INITIAL_INSTALL                 Do initialize DB (for initial install only)"
	@${ECHO} ""

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} \
		${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/README ${RT_PATH}/README
	@${INSTALL_SCRIPT} ${FILESDIR}/ap2mp2-fix.pl ${RT_PATH}/bin
.if !defined(INITIAL_INSTALL)
	@echo Upgrade of RT3 complete.
.else
	-@${PERL} $(RT_PATH)/sbin/rt-setup-database --force --action drop --dba ${DB_DBA_USER} --dba-password ${DB_DBA_PASSWORD}
	-@${PERL} $(RT_PATH)/sbin/rt-setup-database --force --action init --dba ${DB_DBA_USER} --dba-password ${DB_DBA_PASSWORD}
	@${SED} s!%%RT_PATH%%!${RT_PATH}!g ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This program only support perl 5.6.1 or above
.endif

.if ${PERL_LEVEL} == 500601
BUILD_DEPENDS+=	${SITE_PERL}/Encode/compat.pm:${PORTSDIR}/devel/p5-Encode-compat \
		${ARCH_PERL}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv
.endif

.include <bsd.port.post.mk>
