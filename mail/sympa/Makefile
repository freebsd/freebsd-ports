# Ports collection Makefile for:	sympa
# Date created:				29 November 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	sympa
PORTVERSION=	6.1.11
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.sympa.org/distribution/ \
		http://www.sympa.org/distribution/old/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Sympa is an electronic mailing list manager

LICENSE=	GPLv2

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS+=	\
	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI	\
	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy	\
	p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl \
	p5-Term-ProgressBar>=0:${PORTSDIR}/devel/p5-Term-ProgressBar \
	p5-MIME-EncWords>=0:${PORTSDIR}/mail/p5-MIME-EncWords	\
	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools	\
	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools	\
	p5-Msgcat>=0:${PORTSDIR}/misc/p5-Locale-Msgcat \
	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap		\
	p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask	\
	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
	p5-Crypt-CipherSaber>=0:${PORTSDIR}/security/p5-Crypt-CipherSaber \
	p5-HTML-Format>=0:${PORTSDIR}/textproc/p5-HTML-Format	\
	p5-Unicode-LineBreak>=0:${PORTSDIR}/textproc/p5-Unicode-LineBreak \
	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
	p5-HTML-StripScripts-Parser>=0:${PORTSDIR}/www/p5-HTML-StripScripts-Parser \
	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree		\
	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit

# Ignore alpha/beta versions
PORTSCOUT=	limit:^[0-9]+(\.[0-9]+)*$$

USERS=		sympa
GROUPS=		sympa
GNU_CONFIGURE=	yes
USE_PERL5=	yes
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

DB_TYPE:=	${DB_TYPE:L}

.if ${DB_TYPE:Mmysql}
USE_MYSQL=	yes
.endif

.include <bsd.port.options.mk>

.if defined(WITH_FASTCGI)
RUN_DEPENDS+=	p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI
. if !defined(WITHOUT_APACHE)
USE_APACHE=	20+
RUN_DEPENDS+=   ${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
. endif
.endif

.if ${DB_TYPE:Moracle}
RUN_DEPENDS+=	p5-DBD-Oracle>=0:${PORTSDIR}/databases/p5-DBD-Oracle
.elif ${DB_TYPE:Mpg}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.elif ${DB_TYPE:Msybase}
RUN_DEPENDS+=	p5-DBD-Sybase>=0:${PORTSDIR}/databases/p5-DBD-Sybase
.elif ${DB_TYPE:Mmysql}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	DB_TYPE=type	Optional: mysql, Oracle, Pg or Sybase"
	@${ECHO_MSG} "	WITH_FASTCGI	Use FastCGI instead of plain CGI"
	@${ECHO_MSG} "	WITHOUT_APACHE	Use FastCGI without apache (spawn-fcgi or ?)"
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

.include <bsd.port.mk>
