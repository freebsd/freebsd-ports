# Ports collection Makefile for:	sympa
# Date created:				29 November 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	sympa
PORTVERSION=	6.1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.sympa.org/distribution/ \
		http://www.sympa.org/distribution/old/

MAINTAINER=	utisoft@gmail.com
COMMENT=	Sympa is an electronic mailing list manager

BUILD_DEPENDS+=	${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Crypt/CipherSaber.pm:${PORTSDIR}/security/p5-Crypt-CipherSaber \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/${PERL_ARCH}/Locale/Msgcat.pm:${PORTSDIR}/misc/p5-Locale-Msgcat \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_APACHE=	1.3+
CONFIGURE_ARGS+=--prefix=${PREFIX}/sympa \
		--with-confdir=${PREFIX}/etc \
		--with-docdir=${EXAMPLESDIR} \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-etcdir=${PREFIX}/sympa/bin/etc \
		--with-iconsdir=${PREFIX}/www/icons \
		--with-lockdir=/var/spool/lock \
		--mandir=${PREFIX}/man \
		${CONFIGURE_TARGET}
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN8=		alias_manager.8 archived.8 bounced.8 sympa.8

CONFLICTS=	sympa-5*

DB_TYPE=

.include <bsd.port.pre.mk>

.if defined(WITH_FASTCGI)
.	if ${APACHE_VERSION}>=20
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
.	else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
.	endif
BUILD_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
.endif

.if ${DB_TYPE} == "Oracle"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
.else
.	if ${DB_TYPE} == "Pg"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.	else
.		if ${DB_TYPE} == "Sybase"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Sybase.pm:${PORTSDIR}/databases/p5-DBD-Sybase
.		else
.			if ${DB_TYPE} == "mysql"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.			endif
.		endif
.	endif
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    Optional: mysql, Oracle, Pg or Sybase"
	@${ECHO} "      WITH_FASTCGI                    Use FastCGI instead of plain CGI"
	@${ECHO} ""

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-patch:
	${REINPLACE_CMD} -e 's/\$$(DESTDIR)\$$(sampledir)/\$$(sampledir)/g' \
		${WRKSRC}/doc/sample/Makefile.in
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

post-install:
	@PKG_PREFIX=${PREFIX} DB_TYPE=${DB_TYPE} WITH_FASTCGI=${WITH_FASTCGI} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
