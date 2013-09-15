# Created by: chris@shagged.org
# $FreeBSD$

PORTNAME=	tpop3d
PORTVERSION=	1.5.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	tpop3d

MAINTAINER=	boris@tagnet.ru
COMMENT=	Virtual-domain capable POP3 server supporting MySQL, PgSQL etc auth

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-auth-other \
		--enable-tcp-wrappers \
		--enable-tls \
		--with-mailspool-directory=/var/mail

OPTIONS_DEFINE=	LDAP PERLAUTH PASSWDAUTH FLATAUTH GDBMAUTH MAILDIR MBOXINDICES DRAC FIX_PERLAUTH
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

.include <bsd.port.pre.mk>

# MySQL authentication
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-auth-mysql \
			--with-mysql-lib-dir=${LOCALBASE}/lib/mysql \
			--with-mysql-include-dir=${LOCALBASE}/include/mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
DEFAULT_PGSQL_VER=	80
CONFIGURE_ARGS+=	--enable-auth-pgsql \
			--with-pgsql-lib-dir=${LOCALBASE}/lib \
			--with-pgsql-include-dir=${LOCALBASE}/include
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-auth-ldap --with-openldap-root=${LOCALBASE}
.endif

# Perl authentication
.if ${PORT_OPTIONS:MPERLAUTH}
USES+=			perl5
CONFIGURE_ARGS+=	--enable-auth-perl
.endif

.if ${PORT_OPTIONS:MFLATAUTH}
CONFIGURE_ARGS+=	--enable-auth-flatfile
.endif

.if ${PORT_OPTIONS:MGDBMAUTH}
LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--enable-auth-gdbm
.endif

.if ${PORT_OPTIONS:MPASSWDAUTH}
CONFIGURE_ARGS+=	--enable-auth-passwd
.endif

.if ${PORT_OPTIONS:MMAILDIR}
CONFIGURE_ARGS+=	--enable-mbox-maildir
.endif

.if ${PORT_OPTIONS:MMBOXINDICES}
CONFIGURE_ARGS+=	--enable-mbox-bsd-save-indices
.endif

.if ${PORT_OPTIONS:MDRAC}
CONFIGURE_ARGS+=	--enable-drac
BUILD_DEPENDS+=		${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
LDFLAGS+=		-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MFIX_PERLAUTH}
EXTRA_PATCHES+=${PATCHDIR}/extra-patch-auth_perl.c
.endif

USE_RC_SUBR=	tpop3d
DEFAULT_CONFIG=	${PREFIX}/etc/tpop3d.conf.dist

MAN5=		tpop3d.conf.5
MAN8=		tpop3d.8
.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	CHANGES CREDITS FAQ HACKING INSTALL PORTABILITY \
       		README README.POP-before-SMTP README.auth_mysql TODO
.endif

post-patch:
	@${REINPLACE_CMD} 's,^CFLAGS =, CFLAGS = \@CFLAGS\@,' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's,/etc/tpop3d,${PREFIX}/etc/tpop3d,g' \
		${WRKSRC}/tpop3d.conf.5 ${WRKSRC}/tpop3d.8

post-install:
	${INSTALL_DATA} ${FILESDIR}/tpop3d.conf.dist ${DEFAULT_CONFIG}
	@if [ ! -f ${PREFIX}/etc/tpop3d.conf ]; then			\
		${INSTALL_DATA} ${FILESDIR}/tpop3d.conf.dist 		\
			${PREFIX}/etc/tpop3d.conf ;			\
	fi
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
