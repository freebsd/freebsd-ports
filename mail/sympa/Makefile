# Ports collection Makefile for:	sympa
# Date created:				29 November 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	sympa
PORTVERSION=	6.1.6
CATEGORIES=	mail
MASTER_SITES=	http://www.sympa.org/distribution/ \
		http://www.sympa.org/distribution/old/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Sympa is an electronic mailing list manager

BUILD_DEPENDS+=								\
	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI	\
	${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy	\
	${SITE_PERL}/Locale/Messages.pm:${PORTSDIR}/devel/p5-Locale-libintl \
	${SITE_PERL}/Term/ProgressBar.pm:${PORTSDIR}/devel/p5-Term-ProgressBar \
	${SITE_PERL}/MIME/EncWords.pm:${PORTSDIR}/mail/p5-MIME-EncWords	\
	${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools	\
	${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools	\
	${SITE_PERL}/${PERL_ARCH}/Locale/Msgcat.pm:${PORTSDIR}/misc/p5-Locale-Msgcat \
	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap		\
	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask	\
	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
	${SITE_PERL}/Crypt/CipherSaber.pm:${PORTSDIR}/security/p5-Crypt-CipherSaber \
	${SITE_PERL}/HTML/Formatter.pm:${PORTSDIR}/textproc/p5-HTML-Format	\
	${SITE_PERL}/mach/Unicode/LineBreak.pm:${PORTSDIR}/textproc/p5-Unicode-LineBreak \
	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
	${SITE_PERL}/HTML/StripScripts/Parser.pm:${PORTSDIR}/www/p5-HTML-StripScripts-Parser \
	${SITE_PERL}/HTML/Tree.pm:${PORTSDIR}/www/p5-HTML-Tree		\
	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2

# Ignore alpha/beta versions
PORTSCOUT=	limit:^[0-9]+(\.[0-9]+)*$$

USERS=		sympa
GROUPS=		sympa
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_APACHE=	1.3+
ICONSDIR?=	www/icons
CONFIGURE_ARGS+=--bindir=${PREFIX}/libexec/${PORTNAME}	\
		--libexecdir=${PREFIX}/libexec/${PORTNAME} \
		--localedir=${PREFIX}/share/locale	\
		--sbindir=${PREFIX}/libexec/${PORTNAME}	\
		--sysconfdir=${ETCDIR}			\
		--with-confdir=${PREFIX}/etc		\
		--with-docdir=${EXAMPLESDIR}		\
		--with-expldir=${DATADIR}/list_data	\
		--with-iconsdir=${PREFIX}/${ICONSDIR}	\
		--with-initdir=${PREFIX}/etc/rc.d	\
		--with-lockdir=/var/spool/lock		\
		--with-modulesdir=${PREFIX}/libexec/${PORTNAME} \
		--with-piddir=/var/run/${PORTNAME} \
		--with-scriptdir=${PREFIX}/libexec/${PORTNAME} \
		--with-spooldir=/var/spool/${PORTNAME}	\
		--mandir=${MAN8PREFIX}/man
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip
SUB_FILES=	pkg-install

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN8=		alias_manager.8 archived.8 bounced.8 sympa.8

CONFLICTS=	sympa-5*

DB_TYPE=

.if ${DB_TYPE} == "mysql"
USE_MYSQL=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FASTCGI)
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
.endif

.if ${DB_TYPE:L} == "oracle"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
.elif ${DB_TYPE:L} == "pg"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.elif ${DB_TYPE:L} == "sybase"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Sybase.pm:${PORTSDIR}/databases/p5-DBD-Sybase
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Sybase.pm:${PORTSDIR}/databases/p5-DBD-Sybase
.elif ${DB_TYPE:L} == "mysql"
. if exists (${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER}/Makefile)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER}
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER}
. else
IGNORE=	Your MySQL installation is at ${MYSQL_VER}, and there is no p5-DBD-mysql${MYSQL_VER} port
. endif
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	DB_TYPE=type	Optional: mysql, Oracle, Pg or Sybase"
	@${ECHO_MSG} "	WITH_FASTCGI	Use FastCGI instead of plain CGI (Apache only)"
	@${ECHO_MSG} ""

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-patch:
	@${REINPLACE_CMD} -e 's|^\( *staticdir=\).*$$|\1${DATADIR}|'	\
	    -e 's|^\( *defaultdir=\).*$$|\1${EXAMPLESDIR}|'		\
	    -e 's|^\( *arcdir=\).*$$|\1${DATADIR}/arc|'			\
	    -e 's|^\( *bouncedir=\).*$$|\1${DATADIR}/bounce|'		\
	    -e 's|^\( *execcgidir=\).*$$|\1${PREFIX}/libexec/${PORTNAME}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\(--target.*sympa.conf\)|\1.sample|'	\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/\$$(DESTDIR)\$$(sampledir)/\$$(sampledir)/g' \
		${WRKSRC}/doc/sample/Makefile.in

post-install:
	@PKG_PREFIX=${PREFIX} DB_TYPE=${DB_TYPE} WITH_FASTCGI=${WITH_FASTCGI} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
