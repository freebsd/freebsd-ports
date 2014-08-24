# $FreeBSD$

PORTNAME=	sams2
DISTVERSION=	2.0.0
CATEGORIES=	www
MASTER_SITES=	http://sams.perm.ru/download/ http://razumit.ru/

MAINTAINER=	roma.a.g@gmail.com
COMMENT=	Squid Accounting Management System

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server

USES=		gmake libtool tar:bzip2
USE_AUTOTOOLS=	aclocal libtoolize
USE_LDCONFIG=	yes
USE_APACHE=	22+
USE_PHP=	gd mysql zlib
USE_MYSQL=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET= install-strip
CONFIGURE_ARGS+=--datarootdir=${WWWDIR:H}
MAKE_ARGS+=	docdir=${DOCSDIR}

SUB_FILES=	sams2.conf.sample
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${PHP_VER} == "54" && (${APACHE_VERSION} >= 24)
RUN_DEPENDS+=	mod_php5>=0:${PORTSDIR}/www/mod_php5
.endif
.if ${PHP_VER} == "55" && (${APACHE_VERSION} >= 24)
RUN_DEPENDS+=	mod_php55>=0:${PORTSDIR}/www/mod_php55
.endif

.if ${APACHE_VERSION} >= 24
PLIST_SUB+=	AP24=""
.else
PLIST_SUB+=	AP24="@ comment"
.endif

do-configure:
	(cd ${WRKSRC} && make -f Makefile.cvs)
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS})

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/sams2 ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_DATA} ${WRKDIR}/sams2.conf.sample ${STAGEDIR}${PREFIX}/etc
.if ${APACHE_VERSION} >= 24
	${RM} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/*.conf-e
	(cd ${STAGEDIR}${PREFIX}/${APACHEETCDIR} && \
		${MV} doc4sams2.conf doc4sams2.conf.sample && \
		${MV} sams2.conf sams2.conf.sample)
.endif

.include <bsd.port.post.mk>
