# $FreeBSD$

PORTNAME=	amavisd-new
PORTVERSION=	2.10.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://www.ijs.si/software/amavisd/ \
		http://mirrors.catpipe.net/amavisd-new/ \
		http://mirror.mainloop.se/amavisd/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Mail scanner interface between mailer and content checkers

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Unix-Syslog>=0:sysutils/p5-Unix-Syslog \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-Convert-TNEF>=0:converters/p5-Convert-TNEF \
		p5-Convert-UUlib>=1.08,1:converters/p5-Convert-UUlib \
		p5-Archive-Zip>=1.14:archivers/p5-Archive-Zip \
		p5-Net-Server>=2.0:net/p5-Net-Server \
		p5-Mail-DKIM>=0.33:mail/p5-Mail-DKIM \
		p5-Net-LibIDN>=0:dns/p5-Net-LibIDN

USES=		perl5 shebangfix tar:xz
USE_PERL5=	run
SHEBANG_FILES=	amavisd-agent amavisd-nanny amavisd-release p0f-analyzer.pl \
		amavisd-snmp-subagent amavisd

NO_BUILD=	yes

DOCS=		AAAREADME.first AMAVIS-MIB.txt INSTALL LDAP.schema LICENSE \
		RELEASE_NOTES README_FILES/README.* README_FILES/screen.css \
		README_FILES/amavisd-new-docs.html

AMAVISUSER?=	vscan
AMAVISGROUP?=	vscan
USERS=		${AMAVISUSER}
GROUPS=		${AMAVISGROUP}
AMAVISDIR?=	/var/amavis
AMAVISQUARANTINE?=	/var/virusmails
DAEMON?=	/usr/sbin/daemon -p

OPTIONS_DEFINE=	IPV6 BDB SNMP SQLITE MYSQL PGSQL LDAP SASL SPAMASSASSIN P0F ALTERMIME \
		FILE RAR UNRAR ARJ UNARJ LHA ARC NOMARCH CAB RPM ZOO UNZOO LZOP FREEZE \
		P7ZIP MSWORD TNEF DOCS
OPTIONS_DEFAULT=	BDB SPAMASSASSIN FILE UNRAR ARJ LHA ARC CAB RPM ZOO LZOP \
			FREEZE P7ZIP MSWORD
BDB_DESC=		Use BerkeleyDB for nanny/cache/snmp
SNMP_DESC=		Install amavisd snmp subagent
SQLITE_DESC=		Use SQLite for lookups
MYSQL_DESC=		Use MySQL for lookups/logging/quarantine
PGSQL_DESC=		Use PgSQL for lookups/logging/quarantine
LDAP_DESC=		Use LDAP for lookups
SASL_DESC=		Use SASL authentication
SPAMASSASSIN_DESC=	Use mail/spamassassin
P0F_DESC=		Passive operating system fingerprinting
ALTERMIME_DESC=		Use AlterMime for defanging/disclaimers
FILE_DESC=		Use newer file(1) utility from ports
RAR_DESC=		RAR support with archivers/rar
UNRAR_DESC=		RAR support with archivers/unrar
ARJ_DESC=		ARJ support with archivers/arj
UNARJ_DESC=		ARJ support with archivers/unarj
LHA_DESC=		LHA support with archivers/lha
ARC_DESC=		ARC support with archivers/arc
NOMARCH_DESC=		ARC support with archivers/nomarch
CAB_DESC=		CAB support with archivers/cabextract
RPM_DESC=		RPM support with archivers/rpm2cpio
ZOO_DESC=		ZOO support with archivers/zoo
UNZOO_DESC=		ZOO support with archivers/unzoo
LZOP_DESC=		LZOP support with archivers/lzop
FREEZE_DESC=		FREEZE support with archivers/freeze
P7ZIP_DESC=		P7ZIP support with archivers/p7zip
MSWORD_DESC=		Ms Word support with textproc/ripole
TNEF_DESC=		Add external tnef decoder converters/tnef

SUB_FILES=	pkg-deinstall pkg-message

SUB_LIST+=	AMAVISUSER=${AMAVISUSER} \
		AMAVISGROUP=${AMAVISGROUP} \
		AMAVISDIR=${AMAVISDIR} \
		AMAVISQUARANTINE=${AMAVISQUARANTINE} \
		DAEMON="${DAEMON}" \
		PERL=${PERL}

PLIST_SUB+=	AMAVISUSER=${AMAVISUSER} \
		AMAVISGROUP=${AMAVISGROUP} \
		AMAVISDIR=${AMAVISDIR} \
		AMAVISQUARANTINE=${AMAVISQUARANTINE} \
		AMAVIS_NOP0F=${AMAVIS_NOP0F}

.include <bsd.port.options.mk>

USE_RC_SUBR+=	amavisd

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6
.endif

.if ${PORT_OPTIONS:MSNMP} && ${PORT_OPTIONS:MBDB}
USE_RC_SUBR+=	amavisd-snmp
RUN_DEPENDS+=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP
.endif

.if ${PORT_OPTIONS:MBDB}
RUN_DEPENDS+=	p5-BerkeleyDB>=0:databases/p5-BerkeleyDB
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-perl-ldap>=0:net/p5-perl-ldap
.endif

.if ${PORT_OPTIONS:MSASL}
RUN_DEPENDS+=	p5-Authen-SASL>=0:security/p5-Authen-SASL
.endif

.if ${PORT_OPTIONS:MSPAMASSASSIN}
RUN_DEPENDS+=	spamassassin>=0:mail/spamassassin
.endif

.if ${PORT_OPTIONS:MP0F}
RUN_DEPENDS+=	${LOCALBASE}/bin/p0f:net-mgmt/p0f
USE_RC_SUBR+=	amavis-p0fanalyzer
.else
AMAVIS_NOP0F=	"@comment "
.endif

.if ${PORT_OPTIONS:MALTERMIME}
RUN_DEPENDS+=	${LOCALBASE}/bin/altermime:mail/altermime
.endif

.if ${PORT_OPTIONS:MFILE}
# security fix, file >= 4.21 needed
RUN_DEPENDS+=	file>=4.21:sysutils/file
.endif

# archviers/rar is a 32-bit binary port, we don't want the install to fail
# at that port, therefore we will block instantly here if the platform does
# not suit rar.

.if ${PORT_OPTIONS:MRAR}
# support for archivers/rar is broken on ia64
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
RUN_DEPENDS+=	${LOCALBASE}/bin/rar:archivers/rar
.else
IGNORE=	archviers/rar is a 32-bit binary port and is not compatible with ${ARCH}
.endif
.endif

.if ${PORT_OPTIONS:MUNRAR}
RUN_DEPENDS+=	${LOCALBASE}/bin/unrar:archivers/unrar
.endif

.if ${PORT_OPTIONS:MARJ}
RUN_DEPENDS+=	${LOCALBASE}/bin/arj:archivers/arj
.endif

.if ${PORT_OPTIONS:MUNARJ}
RUN_DEPENDS+=	${LOCALBASE}/bin/unarj:archivers/unarj
.endif

.if ${PORT_OPTIONS:MLHA}
RUN_DEPENDS+=	${LOCALBASE}/bin/lha:archivers/lha
.endif

.if ${PORT_OPTIONS:MARC}
RUN_DEPENDS+=	${LOCALBASE}/bin/arc:archivers/arc
.endif

.if ${PORT_OPTIONS:MNOMARCH}
RUN_DEPENDS+=	${LOCALBASE}/bin/nomarch:archivers/nomarch
.endif

.if ${PORT_OPTIONS:MCAB}
RUN_DEPENDS+=	${LOCALBASE}/bin/cabextract:archivers/cabextract
.endif

.if ${PORT_OPTIONS:MRPM}
RUN_DEPENDS+=	${LOCALBASE}/bin/rpm2cpio.pl:archivers/rpm2cpio
.endif

.if ${PORT_OPTIONS:MZOO}
# DOS condition in 2.10.1_2
RUN_DEPENDS+=	zoo>=2.10.1_2:archivers/zoo
.endif

.if ${PORT_OPTIONS:MUNZOO}
RUN_DEPENDS+=	unzoo>=4.4_1:archivers/unzoo
.endif

.if ${PORT_OPTIONS:MLZOP}
RUN_DEPENDS+=	${LOCALBASE}/bin/lzop:archivers/lzop
.endif

.if ${PORT_OPTIONS:MFREEZE}
RUN_DEPENDS+=	${LOCALBASE}/bin/unfreeze:archivers/freeze
.endif

.if ${PORT_OPTIONS:MP7ZIP}
RUN_DEPENDS+=	${LOCALBASE}/bin/7zr:archivers/p7zip
.endif

.if ${PORT_OPTIONS:MMSWORD}
RUN_DEPENDS+=	${LOCALBASE}/bin/ripole:textproc/ripole
.endif

.if ${PORT_OPTIONS:MTNEF}
RUN_DEPENDS+=	${LOCALBASE}/bin/tnef:converters/tnef
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|$daemon_user  = \'vscan\';|$daemon_user  = \'${AMAVISUSER}\';|" \
			-e "s|$daemon_group = \'vscan\';|$daemon_group = \'${AMAVISGROUP}\';|" \
			-e "s|/var/amavis|${AMAVISDIR}|" \
			-e "s|/var/lib/amavis|${AMAVISDIR}|" \
			-e "s|/var/virusmails|${AMAVISQUARANTINE}|" \
			-e 's|$$localhost_name = .localhost.;|$$localhost_name = $$myhostname;|' \
			-e 's|/var/run/clamav/clamd|/var/run/clamav/clamd.sock|g' \
			${WRKSRC}/amavisd.conf
	@${REINPLACE_CMD} "s|/var/amavis/db|${AMAVISDIR}/db|" ${WRKSRC}/amavisd-agent
	@${REINPLACE_CMD} "s|/var/amavis/db|${AMAVISDIR}/db|" ${WRKSRC}/amavisd-nanny
	@${REINPLACE_CMD} -e "s|/var/amavis/db|${AMAVISDIR}/db|" \
			 ${WRKSRC}/amavisd-snmp-subagent
	@${REINPLACE_CMD} "s|/var/amavis/amavisd.sock|${AMAVISDIR}/amavisd.sock|" \
			${WRKSRC}/amavisd-release
	@${REINPLACE_CMD} -e "s|/etc/amavisd.conf|${PREFIX}/etc/amavisd.conf|" \
				-e "s|/var/amavis|${AMAVISDIR}|g" \
				-e 's|$$localhost_name = .localhost.;|$$localhost_name = $$myhostname;|' \
			${WRKSRC}/amavisd

do-install:
.for i in amavisd amavisd-agent amavisd-nanny amavisd-release amavisd-snmp-subagent
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd.conf ${STAGEDIR}${PREFIX}/etc/amavisd.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd.conf-default ${STAGEDIR}${PREFIX}/etc/amavisd.conf-default
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd-custom.conf ${STAGEDIR}${PREFIX}/etc/amavisd-custom.conf.sample
	${LN} -s ${PREFIX}/sbin/amavisd-release ${STAGEDIR}${PREFIX}/sbin/amavisd-requeue
	${MKDIR} ${STAGEDIR}${AMAVISDIR}/var
	${MKDIR} ${STAGEDIR}${AMAVISDIR}/tmp
	${MKDIR} ${STAGEDIR}${AMAVISDIR}/db
	${MKDIR} ${STAGEDIR}${AMAVISQUARANTINE}

do-install-P0F-on:
	${INSTALL_SCRIPT} ${WRKSRC}/p0f-analyzer.pl ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	@${CP} -pr ${WRKSRC}/README_FILES/images/ ${STAGEDIR}${DOCSDIR}/images

.include <bsd.port.post.mk>
