# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	2.0.35
PORTREVISION=	1
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

LATEST_LINK=	apache2

WITH_MPM?=	prefork # or worker, perchild (neither of them still has a problem on FreeBSD)
HTTP_PORT?=	80

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL} \
		--enable-so \
		--with-mpm=${WITH_MPM} \
		--with-port=${HTTP_PORT} \
		--libdir=${PREFIX}/lib/apache2 \
		--includedir=${PREFIX}/include/apache2
CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
SHARED_MODULES= all cgid charset_lite ext_filter case_filter case_filter_in \
		deflate bucketeer
RC_SUB=		-e 's,@@PREFIX@@,${PREFIX},g'

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=YES
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

.if defined(WITH_SUEXEC)
SUEXEC_USERDIR?= public_html
CONFIGURE_ARGS+= --enable-suexec \
		--with-suexec-caller=www \
		--with-suexec-userdir="${SUEXEC_USERDIR}" \
		--with-suexec-uidmin=1000 --with-suexec-gidmin=1000 \
		--with-suexec-docroot="${PREFIX}/www/data" \
		--with-suexec-safepath="${PREFIX}/bin:${LOCALBASE}/bin:/usr/bin:/bin" \
		--with-suexec-logfile="/var/log/httpd-suexec.log"
PLIST_SUB+=	SUEXEC=""
.else
PLIST_SUB+=	SUEXEC="@comment "
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

.if ${WITH_MPM} != "prefork"
PKGNAMESUFFIX=	-${WITH_MPM}
.if !defined(WITH_THREADS)
IGNORE=		"requires threads for ${WITH_MPM} mpm"
.endif
.endif

CONFIGURE_ARGS+= --enable-mods-shared="${SHARED_MODULES}"

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 suexec.8

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${DISTDIR}/powerlogo.gif ${WRKSRC}/docs/icons/freebsd.gif

post-patch:
	@cd ${WRKSRC}/docs/docroot && \
	 for f in index.html.*; do (\
	  ${PERL} -pi -e 's,apache_pb,icons/freebsd.gif" ALT="[Powered by FreeBSD]"><IMG SRC="apache_pb2_ani,g' $$f \
	 ); done
	@${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;
	@${SED} ${RC_SUB} ${FILESDIR}/apache.sh >${WRKDIR}/apache2.sh
.if ${OSVERSION} >= 500032
.for ltfile in srclib/pcre/ltmain.sh srclib/apr/build/ltmain.sh \
		srclib/apr-util/xml/expat/conftools/ltmain.sh
	@${PERL} -pi.orig -e 's|expr|expr --|' \
		${WRKSRC}/${ltfile}
.endfor
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache2.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache2.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache2.sh ${PREFIX}/etc/rc.d/apache2.sh; \
	fi

.include <bsd.port.post.mk>
