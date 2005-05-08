# New ports collection makefile for:	sympa
# Date created:				29 November 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	sympa
PORTVERSION?=	4.1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES?=	http://www.sympa.org/distribution/old/

MAINTAINER=	autrijus@autrijus.org
COMMENT?=	Sympa is an electronic mailing list manager

BUILD_DEPENDS+=	${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Crypt/CipherSaber.pm:${PORTSDIR}/security/p5-Crypt-CipherSaber \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Locale/Msgcat.pm:${PORTSDIR}/misc/p5-Locale-Msgcat \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip
RUN_DEPENDS=	${BUILD_DEPENDS}

DB_TYPE=

.include <bsd.port.pre.mk>

.if defined(WITH_FASTCGI)
.if defined(WITH_APACHE2)
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
.else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
.endif
BUILD_DEPENDS+=		${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
.endif

.if ${DB_TYPE} == "Oracle"
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
.else
.if ${DB_TYPE} == "Pg"
.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg-13
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif
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

HAS_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/sympa \
		--with-confdir=${PREFIX}/etc \
		--with-initdir=${PREFIX}/etc/rc.d \
		--with-etcdir=${PREFIX}/sympa/bin/etc \
		--with-iconsdir=${PREFIX}/www/icons \
		${CONFIGURE_TARGET}
CONFIGURE_ENV+=	lt_cv_sys_max_cmd_len=${CONFIGURE_MAX_CMD_LEN}
MAKE_ENV?=	PERL_EXTUTILS_AUTOINSTALL=--skip

MAN8=		alias_manager.8 archived.8 bounced.8 sympa.8

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
	${MV} ${WRKSRC}/src/etc/script/sympa ${WRKSRC}/src/etc/script/sympa.sh
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

post-install:
	@PKG_PREFIX=${PREFIX} DB_TYPE=${DB_TYPE} WITH_FASTCGI=${WITH_FASTCGI} \
	 ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.if ${ARCH} == "amd64"
BROKEN=		"Configure fails on amd64"
.endif

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
