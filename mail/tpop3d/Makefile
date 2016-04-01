# Created by: chris@shagged.org
# $FreeBSD$

PORTNAME=	tpop3d
PORTVERSION=	1.5.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual-domain capable POP3 server supporting MySQL, PgSQL etc auth

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lcrypto
CONFIGURE_ARGS=	--enable-auth-other \
		--enable-tcp-wrappers \
		--enable-tls \
		--with-mailspool-directory=/var/mail

OPTIONS_DEFINE=	LDAP PERLAUTH PASSWDAUTH FLATAUTH GDBMAUTH MAILDIR MBOXINDICES DRAC FIX_PERLAUTH DOCS
OPTIONS_RADIO=	DB
OPTIONS_RADIO_DB=	MYSQL PGSQL
DB_DESC=		Authentication database
PERLAUTH_DESC=		Use Perl authentication
PASSWDAUTH_DESC=	Use /etc/passwd authentication
FLATAUTH_DESC=		Use /etc/passwd-style flat file authentication
GDBMAUTH_DESC=		Use authentication against GNU dbm files
MAILDIR_DESC=		Compile Maildir support
MBOXINDICES_DESC=	Save Mbox indices
DRAC_DESC=		DRAC RFC for POP-before-SMTP relaying
FIX_PERLAUTH_DESC=	Only try it if perl-auth coredumps

DRAC_CONFIGURE_ENABLE=		drac
MAILDIR_CONFIGURE_ENABLE=	mbox-maildir
PERLAUTH_CONFIGURE_ENABLE=	auth-perl
FLATAUTH_CONFIGURE_ENABLE=	auth-flatfile
GDBMAUTH_CONFIGURE_ENABLE=	auth-gdbm
PASSWDAUTH_CONFIGURE_ENABLE=	auth-passwd
MBOXINDICES_CONFIGURE_ENABLE=	mbox-bsd-save-indices

DRAC_BUILD_DEPENDS=		${LOCALBASE}/lib/libdrac.a:mail/drac
GDBMAUTH_CPPFLAGS=		-I${LOCALBASE}/include
GDBMAUTH_LIB_DEPENDS=		libgdbm.so:databases/gdbm
MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ON=	--enable-auth-mysql \
			--with-mysql-lib-dir=${LOCALBASE}/lib/mysql \
			--with-mysql-include-dir=${LOCALBASE}/include/mysql
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--enable-auth-pgsql \
			--with-pgsql-lib-dir=${LOCALBASE}/lib \
			--with-pgsql-include-dir=${LOCALBASE}/include
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON=	--enable-auth-ldap --with-openldap-root=${LOCALBASE}
PERLAUTH_USES=		perl5
FIX_PERLAUTH_EXTRA_PATCHES=${PATCHDIR}/extra-patch-auth_perl.c

USE_RC_SUBR=	tpop3d
DEFAULT_CONFIG=	${PREFIX}/etc/tpop3d.conf.sample

PORTDOCS=	CHANGES CREDITS FAQ HACKING INSTALL PORTABILITY \
		README README.POP-before-SMTP README.auth_mysql TODO

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS/ s, -g -O2,,' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's,/etc/tpop3d,${PREFIX}/etc/tpop3d,g' \
		${WRKSRC}/tpop3d.conf.5 ${WRKSRC}/tpop3d.8

do-install:
	${INSTALL_DATA} ${FILESDIR}/tpop3d.conf.dist \
		${STAGEDIR}${DEFAULT_CONFIG}
	${INSTALL_MAN} ${WRKSRC}/tpop3d.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/tpop3d.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/tpop3d ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
