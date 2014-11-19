# $FreeBSD$

PORTNAME=	sams2
DISTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://sams.perm.ru/download/ http://razumit.ru/

MAINTAINER=	roma.a.g@gmail.com
COMMENT=	Squid Accounting Management System

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/${_MYSQL_SERVER}

USES=		gmake libtool tar:bzip2
USE_AUTOTOOLS=	aclocal libtoolize
USE_LDCONFIG=	yes
USE_PHP=	gd mysql zlib
USE_MYSQL=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--datarootdir=${WWWDIR:H}
MAKE_ARGS+=	docdir=${DOCSDIR}

SUB_FILES=	sams2.conf.sample
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS APACHE
OPTIONS_SUB=	APACHE
APACHE_USE=	APACHE=22+

# We can't use <options> here, ${APACHE*} won't be populated
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPACHE}
.  if ${PHP_VER} == "54" && (${APACHE_VERSION} >= 24)
RUN_DEPENDS+=	mod_php5>=0:${PORTSDIR}/www/mod_php5
.  endif
.  if ${PHP_VER} == "55" && (${APACHE_VERSION} >= 24)
RUN_DEPENDS+=	mod_php55>=0:${PORTSDIR}/www/mod_php55
.  endif
.  if ${APACHE_VERSION} >= 24
AP24=		""
.  endif
.endif

do-configure:
	(cd ${WRKSRC} && make -f Makefile.cvs)
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS})

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/sams2 ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_DATA} ${WRKDIR}/sams2.conf.sample ${STAGEDIR}${PREFIX}/etc
.if ${PORT_OPTIONS:MAPACHE}
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}
	${SED} -e 's|__WEBPREFIX|${WWWDIR}|g' ${WRKSRC}/etc/httpd_conf \
		> ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/sams2.conf.sample
	${SED} -e 's|__DOCPREFIX|${DOCSDIR}|g' ${WRKSRC}/etc/doc_sams2_conf \
		> ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/doc4sams2.conf.sample
.endif

.include <bsd.port.post.mk>
