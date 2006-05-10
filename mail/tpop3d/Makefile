# New ports collection makefile for:	tpop3d
# Date created:		27 July 2001
# Whom:			chris@shagged.org
#
# $FreeBSD$
#

PORTNAME=	tpop3d
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.ex-parrot.com/~chris/tpop3d/

MAINTAINER=	boris@tagnet.ru
COMMENT=	Virtual-domain capable POP3 server supporting MySQL,PgSQL etc auth

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-auth-other \
		--enable-tcp-wrappers \
		--enable-tls \
		--with-mailspool-directory=/var/mail
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	MYSQL		"Use MySQL authentication"			off \
		PGSQL		"Use PgSQL authentication"			off \
		LDAP		"Use LDAP authentication"			off \
		PERLAUTH	"Use Perl authentication"			off \
		FLATAUTH	"Enable /etc/passwd-style authentication"	off \
		MAILDIR		"Compile Maildir support"			on \
		DRAC		"Enable DRAC RFC for POP-before-SMTP relaying"	off

.include <bsd.port.pre.mk>

# MySQL authentication
.if defined(WITH_MYSQL) && !defined(WITHOUT_MYSQL)
.if defined(WITH_PGSQL) && !defined(WITHOUT_PGSQL)
IGNORE=	MySQL and PgSQL authentication can not be build together
.endif
USE_MYSQL=		yes
DEFAULT_MYSQL_VER=	41
CONFIGURE_ARGS+=	--enable-auth-mysql \
			--with-mysql-lib-dir=${LOCALBASE}/lib/mysql \
			--with-mysql-include-dir=${LOCALBASE}/include/mysql
.endif

.if defined(WITH_PGSQL) && !defined(WITHOUT_PGSQL)
USE_PGSQL=		yes
DEFAULT_PGSQL_VER=	80
CONFIGURE_ARGS+=	--enable-auth-pgsql \
			--with-pgsql-lib-dir=${LOCALBASE}/lib \
			--with-pgsql-include-dir=${LOCALBASE}/include
.endif

.if defined(WITH_LDAP) && !defined(WITHOUT_LDAP)
LIB_DEPENDS+=		ldap-2.2:${PORTSDIR}/net/openldap22-client
CONFIGURE_ARGS+=	--enable-auth-ldap --with-openldap-root=${LOCALBASE}
.endif

# Perl authentication
.if defined(WITH_PERLAUTH) && !defined(WITHOUT_PERLAUTH)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--enable-auth-perl
.endif

.if defined(WITH_FLATAUTH) && !defined(WITHOUT_FLATAUTH)
CONFIGURE_ARGS+=	--enable-auth-flatfile
.endif

.if defined(WITH_MAILDIR) && !defined(WITHOUT_MAILDIR)
CONFIGURE_ARGS+=	--enable-mbox-maildir
.endif

.if defined(WITH_DRAC) && !defined(WITHOUT_DRAC)
CONFIGURE_ARGS+=	--enable-drac
BUILD_DEPENDS+=		${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
LDFLAGS+=		-L${LOCALBASE}/lib
.endif

USE_RC_SUBR=	tpop3d.sh
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
	${INSTALL_SCRIPT} ${FILESDIR}/tpop3d.conf.dist ${DEFAULT_CONFIG}
	@if [ ! -f ${PREFIX}/etc/tpop3d.conf ]; then			\
		${INSTALL_SCRIPT} ${FILESDIR}/tpop3d.conf.dist 		\
			${PREFIX}/etc/tpop3d.conf ;			\
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
