PORTNAME=	sympa
DISTVERSION=	6.2.76
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	dgeo@centrale-med.fr
COMMENT=	Electronic mailing list manager
WWW=		https://www.sympa.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		postfix:mail/postfix
RUN_DEPENDS=	mhonarc>=0:www/mhonarc \
		p5-App-cpanminus>=0:devel/p5-App-cpanminus \
		p5-Archive-Zip>=1.05:archivers/p5-Archive-Zip \
		p5-CGI>=3.51:www/p5-CGI \
		p5-Class-Singleton>=1.03:devel/p5-Class-Singleton \
		p5-Crypt-CipherSaber>=0.50:security/p5-Crypt-CipherSaber \
		p5-Crypt-Eksblowfish>=0.009:security/p5-Crypt-Eksblowfish \
		p5-Crypt-OpenSSL-X509>=1.800.1:security/p5-Crypt-OpenSSL-X509 \
		p5-Crypt-SMIME>=0.15:security/p5-Crypt-SMIME \
		p5-Data-Password>=1.07:security/p5-Data-Password \
		p5-DateTime-Format-Mail>=0.28:devel/p5-DateTime-Format-Mail \
		p5-DateTime-TimeZone>=0.59:devel/p5-DateTime-TimeZone \
		p5-DBD-CSV>=0.22:databases/p5-DBD-CSV \
		p5-DBI>=1.48:databases/p5-DBI \
		p5-Encode-Locale>=1.02:converters/p5-Encode-Locale \
		p5-File-Copy-Recursive>=0.36:devel/p5-File-Copy-Recursive \
		p5-File-NFSLock>=0:devel/p5-File-NFSLock \
		p5-HTML-Format>=0:textproc/p5-HTML-Format \
		p5-HTML-StripScripts-Parser>=1.03:www/p5-HTML-StripScripts-Parser \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-IO-Socket-SSL>=0.90:security/p5-IO-Socket-SSL \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-Locale-libintl>=1.22:devel/p5-Locale-libintl \
		p5-Mail-DKIM>=0.55:mail/p5-Mail-DKIM \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-MIME-Charset>=1.011.3:mail/p5-MIME-Charset \
		p5-MIME-EncWords>=1.014:mail/p5-MIME-EncWords \
		p5-MIME-Lite-HTML>=1.23:mail/p5-MIME-Lite-HTML \
		p5-MIME-Tools>=5.423:mail/p5-MIME-Tools \
		p5-Net-CIDR>=0.16:net-mgmt/p5-Net-CIDR \
		p5-Net-DNS>=0.65:dns/p5-Net-DNS \
		p5-perl-ldap>=0.40:net/p5-perl-ldap \
		p5-Scalar-List-Utils>=1.20:lang/p5-Scalar-List-Utils \
		p5-SOAP-Lite>=0.712:net/p5-SOAP-Lite \
		p5-Template-Toolkit>=2.21:www/p5-Template-Toolkit \
		p5-Term-ProgressBar>=2.09:devel/p5-Term-ProgressBar \
		p5-Time-HiRes>=1.29:devel/p5-Time-HiRes \
		p5-Unicode-LineBreak>=2019.001:textproc/p5-Unicode-LineBreak \
		p5-Unicode-UTF8>=0.62:converters/p5-Unicode-UTF8 \
		p5-URI>=1.35:net/p5-URI \
		p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML

# Shebang is corrected by configure script
USES=		autoreconf cpe fakeroot gettext gmake perl5 shebangfix
USE_GITHUB=	YES
GH_ACCOUNT=	sympa-community
USE_RC_SUBR=	sympa

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin \
			--datadir=${DATADIR} \
			--enable-fhs \
			--libexecdir=${PREFIX}/libexec/${PORTNAME} \
			--localedir=${PREFIX}/share/locale \
			--localstatedir=/var/${PORTNAME} \
			--sbindir=${PREFIX}/libexec/${PORTNAME} \
			--sysconfdir=${ETCDIR} \
			--with-cgidir=${PREFIX}/libexec/${PORTNAME} \
			--with-confdir=${ETCDIR} \
			--with-cssdir=${DATADIR}/static/css \
			--with-defaultdir=${DATADIR}/defaults \
			--with-docdir=${EXAMPLESDIR} \
			--with-expldir=${DATADIR}/list_data \
			--with-lockdir=/var/spool/lock \
			--with-modulesdir=${PREFIX}/libexec/${PORTNAME} \
			--with-picturesdir=${DATADIR}/static/pictures \
			--with-piddir=/var/run/${PORTNAME} \
			--with-scriptdir=${PREFIX}/libexec/${PORTNAME} \
			--with-spooldir=/var/spool/${PORTNAME} \
			--with-staticdir=${DATADIR}/static \
			--without-initdir \
			--without-smrshdir

CONFIGURE_ENV+=	ac_cv_path_POSTALIAS=${LOCALBASE}/sbin/postalias \
		lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip

# Ignore alpha/beta versions
PORTSCOUT=	limit:^[0-9]+(\.[0-9]+)*$$
SUB_FILES=	apache.sample fcgi.sample nginx.sample pkg-install pkg-message

USERS=		sympa
GROUPS=		sympa

PORTEXAMPLES=	*

OPTIONS_DEFINE=		APACHE DOCS EXAMPLES FASTCGI
OPTIONS_DEFAULT=	FASTCGI MYSQL
OPTIONS_RADIO=		DATABASE
OPTIONS_RADIO_DATABASE=	MYSQL PGSQL SQLITE
OPTIONS_SUB=		yes

APACHE_IMPLIES=		FASTCGI
APACHE_RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:www/mod_fastcgi
APACHE_USES=		apache:run
FASTCGI_RUN_DEPENDS=	p5-CGI-Fast>=1.08:www/p5-CGI-Fast \
			p5-FCGI>=0.67:www/p5-FCGI
MYSQL_RUN_DEPENDS=	${DBD_MYSQL}
MYSQL_SUB_LIST=		REQ_MYSQL=mysql
MYSQL_SUB_LIST_OFF=	REQ_MYSQL=""
MYSQL_USES=		mysql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=2.00:databases/p5-DBD-Pg
PGSQL_SUB_LIST=		REQ_PGSQL=postgresql
PGSQL_SUB_LIST_OFF=	REQ_PGSQL=""
SQLITE_RUN_DEPENDS=	p5-DBD-SQLite>=1.31:databases/p5-DBD-SQLite

ICONSDIR?=	www/icons
post-patch:
	@${REINPLACE_CMD} -e 's|^\( *staticdir=\).*$$|\1${DATADIR}|'	\
	    -e 's|^\( *arcdir=\).*$$|\1${DATADIR}/arc|'			\
	    -e 's|^\( *bouncedir=\).*$$|\1${DATADIR}/bounce|'		\
		${WRKSRC}/configure.ac

post-install:
	for link in sympa sympa.pl sympa_wizard.pl upgrade_bulk_spool.pl upgrade_send_spool.pl; do \
		(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -f -s ../libexec/sympa/$$link) \
	done
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS.md ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/apache.sample ${WRKDIR}/nginx.sample \
		${WRKDIR}/fcgi.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
