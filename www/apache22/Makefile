# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	2.0.39
PORTREVISION=	4
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
		http://apache.mirrorcentral.com/dist/httpd/ \
		http://apache.missouri.edu/dist/httpd/ \
		http://ftp.epix.net/apache/dist/httpd/ \
		ftp://ftp.digex.net/pub/packages/network/apache/httpd/ \
		ftp://ftp.cuckoo.com/pub/mirrors/apache/dist/httpd/ \
		http://www.freebsd.org/gifs/:freebsd \
		http://www2.freebsd.org/gifs/:freebsd
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz powerlogo.gif:freebsd
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER?=	perky@fallin.lv

LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2

LATEST_LINK=	apache2

WITH_MPM?=	prefork # or worker, perchild
HTTP_PORT?=	80

HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--enable-so \
		--with-mpm=${WITH_MPM} \
		--with-port=${HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--libdir=${PREFIX_RELDEST}/lib/apache2 \
		--includedir=${PREFIX_RELDEST}/include/apache2
CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}"
SHARED_MODULES= all cgid ext_filter bucketeer
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
RC_SUB=		-e 's,@@PREFIX@@,${PREFIX_RELDEST},g'
MAKE_ENV+=	DESTDIR=${DESTDIR} EXPR_COMPAT=yes

.if defined(NOPORTDOCS)
MAKE_ENV+=	-DNOPORTDOCS
.endif

.if defined(WITH_SUEXEC)
SUEXEC_DOCROOT?= ${PREFIX_RELDEST}/www/data
SUEXEC_USERDIR?= public_html
CONFIGURE_ARGS+= --enable-suexec \
		--with-suexec-caller=www \
		--with-suexec-uidmin=1000 --with-suexec-gidmin=1000 \
		--with-suexec-userdir="${SUEXEC_USERDIR}" \
		--with-suexec-docroot="${SUEXEC_DOCROOT}" \
		--with-suexec-safepath="${PREFIX_RELDEST}/bin:${LOCALBASE}/bin:/usr/bin:/bin" \
		--with-suexec-logfile="/var/log/httpd-suexec.log" \
		--with-suexec-bin="${PREFIX_RELDEST}/sbin/suexec"
PLIST_SUB+=	SUEXEC=""
.else
PLIST_SUB+=	SUEXEC="@comment "
.endif

.if ${WITH_MPM} != "prefork"
PKGNAMESUFFIX=	-${WITH_MPM}
WITH_THREADS=	yes
.if !defined(FORCE_THREADING_MPM)
FORBIDDEN=	"doesn't work with threading MPMs on FreeBSD. If you are\
		brave enough, make again with FORCE_THREADING_MPM=yes"
.endif
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+= --enable-threads
.endif

.if !defined(WITHOUT_SSL) && exists(/usr/lib/libcrypto.so)
SHARED_MODULES+= ssl
PLIST_SUB+=	MODSSL=""
RC_SUB+=	-e 's,@@SSL@@,ssl,g'
.else
PLIST_SUB+=	MODSSL="@comment "
RC_SUB+=	-e 's,@@SSL@@,,g'
.endif

.if !defined(WITHOUT_CACHE) && defined(WITH_THREADS)
SHARED_MODULES+= cache file-cache disk-cache mem_cache
PLIST_SUB+=	MODCACHE=""
.else
PLIST_SUB+=	MODCACHE="@comment "
.endif

.if !defined(WITHOUT_PROXY)
SHARED_MODULES+= proxy proxy-connect proxy-ftp proxy-http
PLIST_SUB+=	MODPROXY=""
.else
PLIST_SUB+=	MODPROXY="@comment "
.endif

.if defined(WITH_EXPERIMENTAL)
SHARED_MODULES+= case_filter case_filter_in deflate ext_filter charset_lite
PLIST_SUB+=	EXPERIMENTAL=""
.else
PLIST_SUB+=	EXPERIMENTAL="@comment "
.endif

CONFIGURE_ARGS+= --enable-mods-shared="${SHARED_MODULES}" ${CONFIGURE_TARGET}

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 suexec.8

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/powerlogo.gif ${WRKSRC}/docs/icons/freebsd.gif

post-patch:
	@cd ${WRKSRC}/docs/docroot && \
	 for f in index.html.*; do (\
	  ${REINPLACE_CMD} -e 's,apache_pb,icons/freebsd.gif"\
		ALT="[Powered by FreeBSD]"><IMG SRC="apache_pb2_ani,g' $$f \
	 ); done
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} -f {} \;
	@${SED} ${RC_SUB} ${FILESDIR}/apache.sh >${WRKDIR}/apache2.sh
	@${SED} ${RC_SUB} ${FILESDIR}/config.layout >>${WRKSRC}/config.layout
	@${RM} -f ${WRKSRC}/docs/manual/index.html.ko.euc-kr

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache2.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache2.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache2.sh ${PREFIX}/etc/rc.d/apache2.sh; \
	fi

.include <bsd.port.mk>
