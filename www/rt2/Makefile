# New ports collection makefile for:   RT2
# Date created:        12 August 2002
# Whom:                plasma
#
# $FreeBSD$
#

PORTNAME=	rt2
PORTVERSION=	2.0.15
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.fsck.com/pub/rt/release/
DISTNAME=	rt-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RT is an industrial-grade ticketing system written in Perl

BUILD_DEPENDS=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/${PERL_ARCH}/Apache/Cookie.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/DBIx/DataSource.pm:${PORTSDIR}/databases/p5-DBIx-DataSource \
		${SITE_PERL}/DBIx/SearchBuilder.pm:${PORTSDIR}/databases/p5-DBIx-SearchBuilder \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM \
		${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/Text/Wrapper.pm:${PORTSDIR}/textproc/p5-Text-Wrapper \
		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash \
		${SITE_PERL}/CGI/Cookie.pm:${PORTSDIR}/www/p5-CGI.pm

WRKSRC=		${WRKDIR}/rt-${RT_VERSION}
RT_VERSION=	${PORTVERSION:C/\./-/g}
DB_TYPE?=	mysql

.include <bsd.port.pre.mk>

.if ${DB_TYPE} == "Pg"
.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg-13
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif
.else
DB_TYPE=	mysql
BUILD_DEPENDS+=	${LOCALBASE}/bin/safe_mysqld:${PORTSDIR}/databases/mysql323-server
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
USE_PERL5=	yes

RT_PATH?=	${PREFIX}/rt2
DB_DBA_PASSWORDD?=
DB_HOST?=	localhost
DB_RT_PASS=	rt_pass

MAN3=		RT::Links.3 \
		RT::Watchers.3 \
		RT::Group.3 \
		RT::Keyword.3 \
		RT::Record.3 \
		RT::ScripConditions.3 \
		RT::Action::Generic.3 \
		RT::Transaction.3 \
		RT::Interface::Email.3 \
		RT::Link.3 \
		RT.3 \
		RT::Watcher.3 \
		RT::ObjectKeywords.3 \
		RT::EasySearch.3 \
		RT::ScripActions.3 \
		RT::Scrip.3 \
		RT::GroupMembers.3 \
		RT::Action::SendPasswordEmail.3 \
		RT::Transactions.3 \
		RT::Scrips.3 \
		RT::Action::SendEmail.3 \
		RT::User.3 \
		RT::ScripCondition.3 \
		RT::Users.3 \
		RT::Ticket.3 \
		RT::ACE.3 \
		RT::Queue.3 \
		RT::Interface::CLI.3 \
		RT::Tickets.3 \
		RT::GroupMember.3 \
		RT::Template.3 \
		RT::Templates.3 \
		RT::Queues.3 \
		RT::Date.3 \
		RT::CurrentUser.3 \
		RT::ScripAction.3 \
		RT::Keywords.3 \
		RT::ObjectKeyword.3 \
		RT::Attachment.3 \
		RT::Groups.3 \
		RT::KeywordSelect.3 \
		RT::Condition::Generic.3 \
		RT::Handle.3 \
		RT::ACL.3 \
		RT::Attachments.3

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	DB_DBA_PASSWORD=password	Your password of MySQL root ();"
	@${ECHO_MSG} "	DB_HOST=hostname		Where MySQL resident (localhost);"
	@${ECHO_MSG} "	DB_RT_PASS=password		Your password of MySQL RT user (rt_pass);"
	@${ECHO_MSG} "	DB_TYPE=type			Pg for postgresql, mysql for MySQL (mysql);"
	@${ECHO_MSG} "	INSTALL_NEW			Install a fresh port, otherwise just upgrade;"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "IMPORTANT!!! If you want to install a fresh new port, define INSTALL_NEW to do so, otherwise this port just do a upgrade."
	@${ECHO_MSG} ""

post-patch:
.for _FILE in tools/testdeps
	${REINPLACE_CMD} 's,/usr/bin/perl,${PERL},' ${WRKSRC}/${_FILE}
	${CHMOD} +x ${WRKSRC}/${_FILE}
.endfor

do-build:
.for _NAME in RT_PATH DB_DBA_PASSWORD DB_HOST DB_RT_PASS DB_TYPE
	@${REINPLACE_CMD} "s!%%${_NAME}%%!${${_NAME}}!g" ${WRKSRC}/Makefile
.endfor
	@cd ${WRKSRC} && ${MAKE} -f ${WRKSRC}/Makefile testdeps
	@cd ${WRKSRC} && ${MAKE} -f ${WRKSRC}/Makefile fixdeps

do-install:
	@${MKDIR} /var/log/rt2
.if defined(INSTALL_NEW)
	-@cd ${WRKSRC} && ${MAKE} -f ${WRKSRC}/Makefile dropdb
	@cd ${WRKSRC} && ${MAKE} -f ${WRKSRC}/Makefile install
.else
	@cd ${WRKSRC} && ${MAKE} -f ${WRKSRC}/Makefile upgrade
.endif
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/rt2/README
	@${CHOWN} -R www /var/log/rt2

post-install:
	@${SED} s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

.include <bsd.port.post.mk>
