# New ports collection makefile for:	tpop3d
# Date created:		27 July 2001
# Whom:			chris@shagged.org
#
# $FreeBSD$
#

PORTNAME=	tpop3d
PORTVERSION=	1.4.2
CATEGORIES=	mail
MASTER_SITES=	http://www.ex-parrot.com/~chris/tpop3d/

MAINTAINER=	chris@shagged.org

# mysql authentication
.if !defined(WITHOUT_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif
.if defined(WITH_LDAP)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2
.endif

# perl authentication
.if defined(WITH_PERLAUTH)
USE_PERL5=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-auth-other \
		--enable-tcp-wrappers \
		--with-mailspool-directory=/var/mail

.if !defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--enable-auth-mysql --with-mysql-root=${LOCALBASE}
.endif
.if defined(WITH_PERLAUTH)
CONFIGURE_ARGS+=	--enable-auth-perl
.endif
.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--enable-auth-ldap --with-openldap-root=${LOCALBASE}
.endif
.if !defined(WITHOUT_MAILDIR)
CONFIGURE_ARGS+=	--enable-mbox-maildir
.endif

SAMPLE_RCD=	tpop3d.sh.sample
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${SAMPLE_RCD}
DEFAULT_CONFIG=	${PREFIX}/etc/tpop3d.conf.dist

MAN5=		tpop3d.conf.5
MAN8=		tpop3d.8

post-patch:
	@${PERL} -pi -e 's,^CFLAGS =, CFLAGS = \@CFLAGS\@,' \
		${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's,/etc/tpop3d,${PREFIX}/etc/tpop3d,g' \
		${WRKSRC}/tpop3d.conf.5 ${WRKSRC}/tpop3d.8

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/tpop3d.conf.dist ${DEFAULT_CONFIG}
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${INSTALL_SCRIPT} ${FILESDIR}/${SAMPLE_RCD}		\
			${STARTUP_SCRIPT} ;				\
	fi
	@if [ ! -f ${PREFIX}/etc/tpop3d.conf ]; then			\
		${INSTALL_SCRIPT} ${FILESDIR}/tpop3d.conf.dist 		\
			${PREFIX}/etc/tpop3d.conf ;			\
	fi

.include <bsd.port.mk>
