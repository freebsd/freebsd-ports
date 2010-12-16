# New ports collection makefile for:    maia
# Date created:                         03 Jan 2008
# Whom:                                 Janky Jay <ek@purplehat.org>
#
# $FreeBSD$
#
# Based on amavisd-new ports makefile.

PORTNAME=	maia
PORTVERSION=	1.0.2a
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.purplehat.org/downloads/maia/

MAINTAINER=	ek@purplehat.org
COMMENT=	A web-based management system based on amavisd-new and SpamAssassin

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
		p5-Convert-UUlib>=1.08,1:${PORTSDIR}/converters/p5-Convert-UUlib \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Net-Server>=0.93:${PORTSDIR}/net/p5-Net-Server

USE_PERL5_RUN=	5.8.2+

NO_BUILD=	yes

DOCS=	LICENSE README amavisd.conf.dist maia-mysql.sql maia-pgsql.sql maia.conf.dist

MAIAUSER?=	vscan
MAIAGROUP?=	vscan
MAIADIR?=	/var/amavisd
MAIAQUARANTINE?=	/var/amavisd/virusmails

OPTIONS=	BDB	"Use BerkeleyDB"	on \
		MYSQL	"Use MySQL"		on \
		PGSQL	"Use PgSQL"		off \
		SPAMASSASSIN	"Use SpamAssassin"	on \
		ALTERMIME	"Use AlterMime"	off \
		CRYPT	"Encryption support"	on \
		IPCOUNTRY	"SpamAssassin IP Country plugin"	on \
		DOMAINKEYS	"SpamAssassin DomainKey plugin"	on \
		SPFQUERY	"SpamAssassin SPF Query plugin"	on \
		FILE	"Use newer file(1) utility from ports"	on \
		RAR	"RAR support with archivers/rar"	off \
		UNRAR	"RAR support with archivers/unrar"	on \
		ARJ	"ARJ support with archivers/arj"	on \
		UNARJ	"ARJ support with archivers/unarj"	off \
		LHA	"LHA support with archivers/lha"	on \
		ARC	"ARC support with archivers/arc"	on \
		NOMARCH	"ARC support with archivers/nomarch"	off \
		CAB	"CAB support with archivers/cabextract"	on \
		RPM	"RPM support with archivers/rpm2cpio"	on \
		ZOO	"ZOO support with archivers/zoo"	on \
		UNZOO	"ZOO support with archivers/unzoo"	off \
		LZOP	"LZOP support with archivers/lzop"	on \
		FREEZE	"FREEZE support with archivers/freeze"	on \
		P7ZIP	"P7ZIP support with archivers/p7zip"	on \
		TNEF	"Add external tnef decoder converters/tnef"	off

SUB_FILES=	pkg-install pkg-deinstall pkg-message

SUB_LIST+=	MAIAUSER=${MAIAUSER} \
		MAIAGROUP=${MAIAGROUP} \
		MAIADIR=${MAIADIR} \
		MAIAQUARANTINE=${MAIAQUARANTINE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

USE_RC_SUBR+=	maia.sh

.if defined(WITH_BDB)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(WITH_ALTERMIME)
RUN_DEPENDS+=	${LOCALBASE}/bin/altermime:${PORTSDIR}/mail/altermime
.endif

.if defined(WITH_CRYPT)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC
.endif

.if defined(WITH_IPCOUNTRY)
RUN_DEPENDS+=	${SITE_PERL}/IP/Country.pm:${PORTSDIR}/net/p5-IP-Country
.endif

.if defined(WITH_DOMAINKEYS)
RUN_DEPENDS+=	${SITE_PERL}/Mail/DomainKeys.pm:${PORTSDIR}/mail/p5-Mail-DomainKeys
.endif

.if defined(WITH_SPFQUERY)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SPF/Query.pm:${PORTSDIR}/mail/p5-Mail-SPF-Query
.endif

.if defined(WITH_FILE)
# security fix, file > 4.21 needed
RUN_DEPENDS+=	file>=4.21:${PORTSDIR}/sysutils/file
.endif

# archviers/rar is a 32-bit binary port, we don't want the install to fail
# at that port, therefore we will block instantly here if the platform does
# not suit rar.

.if defined(WITH_RAR)
IA32_BINARY_PORT=	yes
RUN_DEPENDS+=	${LOCALBASE}/bin/rar:${PORTSDIR}/archivers/rar
.endif

.if defined(WITH_UNRAR)
RUN_DEPENDS+=	${LOCALBASE}/bin/unrar:${PORTSDIR}/archivers/unrar
.endif

.if defined(WITH_ARJ)
RUN_DEPENDS+=	${LOCALBASE}/bin/arj:${PORTSDIR}/archivers/arj
.endif

.if defined(WITH_UNARJ)
RUN_DEPENDS+=	${LOCALBASE}/bin/unarj:${PORTSDIR}/archivers/unarj
.endif

.if defined(WITH_LHA)
RUN_DEPENDS+=	${LOCALBASE}/bin/lha:${PORTSDIR}/archivers/lha
.endif

.if defined(WITH_ARC)
RUN_DEPENDS+=	${LOCALBASE}/bin/arc:${PORTSDIR}/archivers/arc
.endif

.if defined(WITH_NOMARCH)
RUN_DEPENDS+=	${LOCALBASE}/bin/nomarch:${PORTSDIR}/archivers/nomarch
.endif

.if defined(WITH_CAB)
RUN_DEPENDS+=	${LOCALBASE}/bin/cabextract:${PORTSDIR}/archivers/cabextract
.endif

.if defined(WITH_RPM)
RUN_DEPENDS+=	${LOCALBASE}/bin/rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
.endif

.if defined(WITH_ZOO)
# DOS condition in 2.10.1_2
RUN_DEPENDS+=	zoo>=2.10.1_2:${PORTSDIR}/archivers/zoo
.endif

.if defined(WITH_UNZOO)
RUN_DEPENDS+=	unzoo>=4.4_1:${PORTSDIR}/archivers/unzoo
.endif

.if defined(WITH_LZOP)
RUN_DEPENDS+=	${LOCALBASE}/bin/lzop:${PORTSDIR}/archivers/lzop
.endif

.if defined(WITH_FREEZE)
RUN_DEPENDS+=	${LOCALBASE}/bin/unfreeze:${PORTSDIR}/archivers/freeze
.endif

.if defined(WITH_P7ZIP)
RUN_DEPENDS+=	${LOCALBASE}/bin/7zr:${PORTSDIR}/archivers/p7zip
.endif

.if defined(WITH_TNEF)
RUN_DEPENDS+=	${LOCALBASE}/bin/tnef:${PORTSDIR}/converters/tnef
.endif

post-patch:
.for f in amavisd.conf.dist amavisd-maia
	@${REINPLACE_CMD} "s@'zoo'\]@['zoo','unzoo'] ]@" ${WRKSRC}/${f}
.endfor
.for i in amavisd.conf.dist amavisd-maia
	@${REINPLACE_CMD} -e "s|$daemon_user  = \'amavis\';|$daemon_user  = \'${MAIAUSER}\';|" \
		-e "s|$daemon_group = \'amavis\';|$daemon_group = \'${MAIAGROUP}\';|" \
		-e 's|$$log_level = 0;|$$log_level = 1;|' \
		-e 's|/etc/amavisd.conf|${PREFIX}/etc/amavisd.conf|' \
		-e "s|/var/virusmails|${MAIAQUARANTINE}|" ${WRKSRC}/${i}
.endfor
.for f in amavisd-maia amavisd.conf.dist maia.conf.dist scripts/send-quarantine-digests.pl \
	scripts/process-quarantine.pl scripts/load-sa-rules.pl
		@${REINPLACE_CMD} "s|/var/amavisd|${MAIADIR}|" ${WRKSRC}/${f}
.endfor
.for i in maia.conf.dist scripts/expire-quarantine-cache.pl scripts/stats-snapshot.pl \
	scripts/maiadbtool.pl scripts/configtest.pl scripts/send-quarantine-reminders.pl \
	scripts/send-quarantine-digests.pl scripts/process-quarantine.pl \
	scripts/load-sa-rules.pl scripts/process-quarantine-sub.pl
		@${REINPLACE_CMD} "s|/etc/maia.conf|${PREFIX}/etc/maia.conf|" ${WRKSRC}/${i}
.endfor

pre-install:
	${FIND} ${WRKSRC} -name '*.bak' -delete
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
	@${INSTALL} -d ${WWWDIR}
	cd ${WRKSRC}/php && ${FIND} . | ${CPIO} --quiet -pdm -L ${WWWDIR}
	cd ${WRKSRC}/scripts && ${FIND} . | ${CPIO} --quiet -pdm -L ${MAIADIR}/maia/scripts
	cd ${WRKSRC}/templates && ${FIND} . | ${CPIO} --quiet -pdm -L ${MAIADIR}/maia/templates

.for i in amavisd-maia
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/sbin
.endfor
	${INSTALL_SCRIPT} -m 640 ${WRKSRC}/amavisd.conf.dist ${PREFIX}/etc/amavisd.conf.dist
	${INSTALL_SCRIPT} -m 640 ${WRKSRC}/maia.conf.dist ${PREFIX}/etc/maia.conf.dist
#
#  This can contain sensitive information, e.g. SQL passwords, so it should be handled
#  with care.
#
.if !exists(${PREFIX}/www/${PORTNAME}/config.php)
	${INSTALL} -o ${WWWOWN} -g ${WWWGRP} -m 640 ${WRKSRC}/php/config.php.dist \
		${PREFIX}/www/${PORTNAME}/config.php
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
post-install:
	@if [ ! -f ${PREFIX}/etc/amavisd.conf ]; then \
	${CP} -p ${PREFIX}/etc/amavisd.conf.dist ${PREFIX}/etc/amavisd.conf ; fi
	@if [ ! -f ${PREFIX}/etc/maia.conf ]; then \
	${CP} -p ${PREFIX}/etc/maia.conf.dist ${PREFIX}/etc/maia.conf ; fi
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHOWN} -R ${MAIAUSER}:${MAIAGROUP} ${MAIADIR}/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${MAIAUSER}:${MAIAGROUP} ${MAIADIR}' >> ${TMPPLIST}
	${LN} -s ${PREFIX}/share/smarty ${PREFIX}/www/${PORTNAME}/libs/Smarty
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
