# New ports collection makefile for:	sympa5
# Date created:		16 September 2005
# Whom:			Olivier Girard <Olivier.Girard@Univ-Angers.fr>
#
# $FreeBSD$
#

PORTNAME=	sympa
PORTVERSION=	5.4.7
CATEGORIES=	mail
MASTER_SITES?=	http://www.sympa.org/distribution/

MAINTAINER=	Olivier.Girard@univ-angers.fr
COMMENT=	Sympa is an electronic mailing list manager

BUILD_DEPENDS+=	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/MIME/EncWords.pm:${PORTSDIR}/mail/p5-MIME-EncWords \
		${SITE_PERL}/File/NFSLock.pm:${PORTSDIR}/devel/p5-File-NFSLock \
		${SITE_PERL}/Locale/TextDomain.pm:${PORTSDIR}/devel/p5-Locale-libintl \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/Crypt/CipherSaber.pm:${PORTSDIR}/security/p5-Crypt-CipherSaber \
		${SITE_PERL}/mach/Crypt/OpenSSL/X509.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-X509 \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/bin/mhonarc:${PORTSDIR}/www/mhonarc
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	sympa5
USE_APACHE=	1.3+
HAS_CONFIGURE=	yes
USE_PERL5=	5.8.6+
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--with-confdir=${PREFIX}/etc/sympa \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-etcdir=${PREFIX}/etc/sympa \
		--with-cgidir=${PREFIX}/sympa/cgi-bin \
		--with-iconsdir=${PREFIX}/sympa/icons \
		--with-sbindir=${PREFIX}/sbin \
		--with-libdir=${PREFIX}/lib/sympa \
		--with-libexecdir=${PREFIX}/libexec/sympa \
		--with-datadir=${DATADIR} \
		--with-expldir=${PREFIX}/sympa/expl \
		--with-lockdir=/var/spool/lock \
		--with-piddir=/var/run \
		--with-localedir=${PREFIX}/share/locale \
		--with-docdir=${DOCSDIR} \
		--with-sampledir=${EXAMPLESDIR} \
		--with-spooldir=${PREFIX}/sympa/spool \
		--enable-secure
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip

MAN8=		alias_manager.8 archived.8 bounced.8 sympa.8

CONFLICTS=	sympa-4* sympa-5.[0-2]*

DB_TYPE?=mysql

PORTDOCS=	*

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FASTCGI)
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
BUILD_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
.endif

.if ${DB_TYPE} == "Oracle"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
.else
.if ${DB_TYPE} == "Pg"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.else
.if ${DB_TYPE} == "Sybase"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Sybase.pm:${PORTSDIR}/databases/p5-DBD-Sybase
.else
.if ${DB_TYPE} == "mysql"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.endif
.endif
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    Optional: mysql, Oracle, Pg or Sybase"
	@${ECHO} "      WITHOUT_FASTCGI                 Use plain CGI instead of FastCGI"
	@${ECHO} ""

post-patch:
	${MV} ${WRKSRC}/src/etc/script/sympa ${WRKSRC}/src/etc/script/sympa.sh
	@${REINPLACE_CMD} -E 's,^(INITSRC.*=.*sympa)$$,\1.sh,' \
		${WRKSRC}/src/etc/script/Makefile
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's, locale$$,,g' \
			  -e 's, installlocale,,g' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's, checklocales,,' \
		${WRKSRC}/po/Makefile
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, installdoc,,g' -e 's, $$(DOCDIR),,g'\
		${WRKSRC}/Makefile.in
.endif
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@PKG_PREFIX=${PREFIX} DB_TYPE=${DB_TYPE} WITH_FASTCGI=${WITH_FASTCGI} \
	 ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/alias_manager.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/archived.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/bounced.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/doc/man8/sympa.8 ${MAN8PREFIX}/man/man8/

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
