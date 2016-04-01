# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	sympa
PORTVERSION=	6.2.14
CATEGORIES=	mail
MASTER_SITES=	http://www.sympa.org/distribution/ \
		http://www.sympa.org/distribution/old/

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Sympa is an electronic mailing list manager

LICENSE=	GPLv2

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
	p5-DBI>=0:databases/p5-DBI	\
	p5-Class-Singleton>=0:devel/p5-Class-Singleton	\
	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive	\
	p5-IO-stringy>=0:devel/p5-IO-stringy	\
	p5-Locale-libintl>=0:devel/p5-Locale-libintl	\
	p5-Term-ProgressBar>=0:devel/p5-Term-ProgressBar	\
	p5-MIME-EncWords>=0:mail/p5-MIME-EncWords	\
	p5-MIME-Tools>=0:mail/p5-MIME-Tools	\
	p5-Mail-Tools>=0:mail/p5-Mail-Tools	\
	p5-Msgcat>=0:misc/p5-Locale-Msgcat	\
	p5-perl-ldap>=0:net/p5-perl-ldap	\
	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask	\
	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL	\
	p5-Crypt-CipherSaber>=0:security/p5-Crypt-CipherSaber	\
	p5-HTML-Format>=0:textproc/p5-HTML-Format	\
	p5-Unicode-LineBreak>=0:textproc/p5-Unicode-LineBreak	\
	p5-XML-LibXML>=0:textproc/p5-XML-LibXML	\
	p5-HTML-StripScripts-Parser>=0:www/p5-HTML-StripScripts-Parser	\
	p5-HTML-Tree>=0:www/p5-HTML-Tree	\
	p5-Template-Toolkit>=0:www/p5-Template-Toolkit	\
	p5-MIME-Lite-HTML>=0:mail/p5-MIME-Lite-HTML	\
	p5-Net-DNS>=0:dns/p5-Net-DNS	\
	p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail	\
	p5-DateTime-TimeZone>=0:devel/p5-DateTime-TimeZone	\
	p5-Email-Simple>=0:mail/p5-Email-Simple	\
	p5-File-NFSLock>=0:devel/p5-File-NFSLock	\
	p5-MIME-Charset>=0:mail/p5-MIME-Charset	\
	p5-Net-CIDR>=0:net-mgmt/p5-Net-CIDR	\
	p5-Proc-ProcessTable>=0:devel/p5-Proc-ProcessTable	\
	p5-Time-HiRes>=0:devel/p5-Time-HiRes	\
	p5-Crypt-SMIME>=0:security/p5-Crypt-SMIME	\
	p5-CGI>=0:www/p5-CGI \
	p5-Data-Password>=0:security/p5-Data-Password

# Ignore alpha/beta versions
PORTSCOUT=	limit:^[0-9]+(\.[0-9]+)*$$

PORTDOCS=	NEWS

USERS=		sympa
GROUPS=		sympa
# Shebang is corrected by configure script
USES=		cpe fakeroot perl5
GNU_CONFIGURE=	yes
ICONSDIR?=	www/icons
CONFIGURE_ARGS+=--bindir=${PREFIX}/bin \
		--libexecdir=${PREFIX}/libexec/${PORTNAME} \
		--localedir=${PREFIX}/share/locale	\
		--sbindir=${PREFIX}/libexec/${PORTNAME}	\
		--datadir=${DATADIR}	\
		--sysconfdir=${ETCDIR}			\
		--with-confdir=${ETCDIR}		\
		--with-docdir=${EXAMPLESDIR}		\
		--with-expldir=${DATADIR}/list_data	\
		--with-defaultdir=${DATADIR}/defaults	\
		--with-initdir=${PREFIX}/etc/rc.d	\
		--with-lockdir=/var/spool/lock		\
		--with-modulesdir=${PREFIX}/libexec/${PORTNAME} \
		--with-piddir=/var/run/${PORTNAME} \
		--with-scriptdir=${PREFIX}/libexec/${PORTNAME} \
		--with-spooldir=/var/spool/${PORTNAME} \
		--with-cgidir=${PREFIX}/libexec/${PORTNAME}	\
		--without-smrshdir

CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip
SUB_FILES=	pkg-install pkg-message apache.sample nginx.sample fcgi.sample
SUB_LIST=	DB_TYPE=${DB_TYPE} PERL=${PERL} WRKSRC=${WRKSRC} BINDIR=${STAGEDIR}${PREFIX}
PORTEXAMPLES=	*

USE_RC_SUBR=	sympa

CONFLICTS=	sympa-5*

OPTIONS_DEFINE=	FASTCGI APACHE NLS
OPTIONS_DEFAULT=APACHE
OPTIONS_RADIO=	DATABASE
OPTIONS_RADIO_DATABASE=	ORACLE PGSQL SYBASE MYSQL
OPTIONS_SUB=	yes

SYBASE_DESC=	Sybase database

.ifdef DB_TYPE
DB_TYPE:=	${DB_TYPE:tu}
.  for option in ${OPTIONS_RADIO_DATABASE}
.    if ${DB_TYPE} == ${option:S,PGSQL,PG,}
OPTIONS_SET+=	${option}
.warning You need to replace your DB_TYPE variable in make.conf with mail_sympa_SET+=${option}
.    endif
.  endfor
.endif

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
FASTCGI_RUN_DEPENDS=	p5-FCGI>=0:www/p5-FCGI
APACHE_IMPLIES=	FASTCGI
APACHE_USE=	APACHE_RUN=22+
APACHE_RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:www/mod_fastcgi

ORACLE_RUN_DEPENDS=	p5-DBD-Oracle>=0:databases/p5-DBD-Oracle
ORACLE_VARS=	DB_TYPE=oracle
PGSQL_SUB_LIST=	REQ_PGSQL=postgresql
PGSQL_SUB_LIST_OFF=	REQ_PGSQL=""
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PGSQL_VARS=	DB_TYPE=Pg
SYBASE_RUN_DEPENDS=	p5-DBD-Sybase>=0:databases/p5-DBD-Sybase
SYBASE_VARS=	DB_TYPE=sybase
MYSQL_SUB_LIST=	REQ_MYSQL=mysql
MYSQL_SUB_LIST_OFF=	REQ_MYSQL=""
MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
MYSQL_VARS=	DB_TYPE=mysql

post-patch:
	@${REINPLACE_CMD} -e 's|^\( *staticdir=\).*$$|\1${DATADIR}|'	\
	    -e 's|^\( *arcdir=\).*$$|\1${DATADIR}/arc|'			\
	    -e 's|^\( *bouncedir=\).*$$|\1${DATADIR}/bounce|'		\
	    -e 's|^\( *defaultdir=\).*$$|\1${DATADIR}/defaults|'		\
	    -e 's|^\( *execcgidir=\).*$$|\1${PREFIX}/libexec/${PORTNAME}|' \
		${WRKSRC}/configure

post-install:
	for link in sympa.pl sympa_wizard.pl upgrade_bulk_spool.pl upgrade_send_spool.pl; do \
		(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -f -s ../libexec/sympa/$$link) \
	done
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/apache.sample ${WRKDIR}/nginx.sample \
		${WRKDIR}/fcgi.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
