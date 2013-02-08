# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	1.0.1p1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/287/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework library for access to Prelude NIDS database

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		prelude:${PORTSDIR}/security/libprelude \
		nettle:${PORTSDIR}/security/nettle \
		p11-kit:${PORTSDIR}/security/p11-kit

USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes

CONFIGURE_ARGS=	--enable-gtk-doc=no
USE_LDCONFIG=	yes

MAN1=		preludedb-admin.1
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS MYSQL PERL PGSQL PYTHON SQLITE
OPTIONS_DEFAULT=MYSQL
PERL_DESC=	Perl bindings
MYSQL_DESC=	MySQL plugin
PQSQL_DESC=	PostgreSQL plugin
SQLITE_DESC=	SQLite3 plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON="" PYTHON_VER=${PYTHON_VER}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		WITH_MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		WITH_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql
PLIST_SUB+=		WITH_PGSQL=""
.else
CONFIGURE_ARGS+=	--without-postgresql
PLIST_SUB+=		WITH_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite3
PLIST_SUB+=		WITH_SQLITE=""
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=		WITH_SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MPERL}
	@${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/perllocal.pod
.endif
	@${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
