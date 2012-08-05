# New ports collection makefile for:	tpop3d
# Date created:		27 July 2001
# Whom:			chris@shagged.org
#
# $FreeBSD$
#

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

OPTIONS=	MYSQL		"Use MySQL authentication"			off \
		PGSQL		"Use PgSQL authentication"			off \
		LDAP		"Use LDAP authentication"			off \
		PERLAUTH	"Use Perl authentication"			off \
		PASSWDAUTH	"Use /etc/passwd authentication"		off \
		FLATAUTH	"Use /etc/passwd-style flat file authentication"	off \
		GDBMAUTH        "Use authentication against GNU dbm files"      off \
		MAILDIR		"Compile Maildir support"			on \
		MBOXINDICES	"Save Mbox indices"				off \
		DRAC		"Enable DRAC RFC for POP-before-SMTP relaying"	off \
		FIX_PERLAUTH	"Only try it if perl-auth coredumps"		off

.include <bsd.port.pre.mk>

# MySQL authentication
.if defined(WITH_MYSQL)
.if defined(WITH_PGSQL)
BROKEN=	MySQL and PgSQL authentication can not be build together
.endif
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-auth-mysql \
			--with-mysql-lib-dir=${LOCALBASE}/lib/mysql \
			--with-mysql-include-dir=${LOCALBASE}/include/mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
DEFAULT_PGSQL_VER=	80
CONFIGURE_ARGS+=	--enable-auth-pgsql \
			--with-pgsql-lib-dir=${LOCALBASE}/lib \
			--with-pgsql-include-dir=${LOCALBASE}/include
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-auth-ldap --with-openldap-root=${LOCALBASE}
.endif

# Perl authentication
.if defined(WITH_PERLAUTH)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--enable-auth-perl
.endif

.if defined(WITH_FLATAUTH)
CONFIGURE_ARGS+=	--enable-auth-flatfile
.endif

.if defined(WITH_GDBMAUTH)
LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--enable-auth-gdbm
.endif

.if defined(WITH_PASSWDAUTH)
CONFIGURE_ARGS+=	--enable-auth-passwd
.endif

.if defined(WITH_MAILDIR)
CONFIGURE_ARGS+=	--enable-mbox-maildir
.endif

.if defined(WITH_MBOXINDICES)
CONFIGURE_ARGS+=	--enable-mbox-bsd-save-indices
.endif

.if defined(WITH_DRAC)
CONFIGURE_ARGS+=	--enable-drac
BUILD_DEPENDS+=		${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
LDFLAGS+=		-L${LOCALBASE}/lib
.endif

.if defined(WITH_FIX_PERLAUTH)
EXTRA_PATCHES+=${PATCHDIR}/extra-patch-auth_perl.c
.endif

USE_RC_SUBR=	tpop3d
DEFAULT_CONFIG=	${PREFIX}/etc/tpop3d.conf.dist

MAN5=		tpop3d.conf.5
MAN8=		tpop3d.8
.if !defined(NOPORTDOCS)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
