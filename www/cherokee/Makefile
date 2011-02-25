# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
PORTVERSION=	1.0.19
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/1.0/${PORTVERSION}/ \
		http://cherokee.osuosl.org/1.0/${PORTVERSION}/ \
		http://mirror.its.uidaho.edu/pub/cherokee/1.0/\${PORTVERSION}/ \
		http://www.gtlib.gatech.edu/pub/cherokee/1.0/\${PORTVERSION}/ \
		ftp://mirrors.secution.com/cherokee/1.0/${PORTVERSION}/ \
		ftp://ftp.easynet.be/cherokee/1.0/${PORTVERSION}/ \
		http://ftp.heanet.ie/mirrors/cherokee/1.0/${PORTVERSION}/ \
		http://www.ftp.ne.jp/infosystems/cherokee/1.0/${PORTVERSION}/ \
		http://www.ring.gr.jp/archives/net/cherokee/1.0/${PORTVERSION}/ \
		http://ftp.nluug.nl/pub/internet/cherokee/1.0/${PORTVERSION}/ \
		http://ftp.surfnet.nl/pub/internet/cherokee/1.0/${PORTVERSION}/ \
		http://mirror.is.co.za/mirrors/cherokee/1.0/${PORTVERSION}/ \
		http://mirror.aarnet.edu.au/pub/cherokee/1.0/\${PORTVERSION}/ \
		http://ftp.ntua.gr/pub/www/cherokee/1.0/\${PORTVERSION}/ \
		http://ftp.cc.uoc.gr/mirrors/cherokee/1.0/\${PORTVERSION}/ \
		http://cherokee.mirror.garr.it/mirrors/cherokee/1.0/\${PORTVERSION}/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/network/cherokee/1.0/\${PORTVERSION}/ \
		http://ftp.icm.edu.pl/packages/cherokee/1.0/\${PORTVERSION}/ \
		ftp://download.srv.ro/pub/cherokee/1.0/\${PORTVERSION}/ \
		http://mirror.yandex.ru/mirrors/cherokee-project.com/1.0/\${PORTVERSION}/ \
		http://cherokee.hyperial.com/1.0/\${PORTVERSION}/ \
		http://cherokee.labs.itb.ac.id/1.0/\${PORTVERSION}/ \
		http://mirror.cpsc.ucalgary.ca/mirror/cherokee/1.0/\${PORTVERSION}/ \
		http://www.feel3.de/mirrors/cherokee/1.0/\${PORTVERSION}/ \
		http://cherokee.pubcrawler.com/1.0/\${PORTVERSION}/

# Disabled mirrors
# due to 404
#		http://cherokee-project.pl/mirror/cherokee/1.0/${PORTVERSION}/ \
#		http://ftp.saix.net/Cherokee/1.0/${PORTVERSION}/ \
#		http://sunsite.rediris.es/mirror/cherokee/1.0/\${PORTVERSION}/

# due to site down
#		http://mirror.apung.web.id/cherokee/1.0/\${PORTVERSION}/ \

MAINTAINER=	dschulz@gmail.com
COMMENT=	Extremely fast and flexible web server

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_RC_SUBR=	cherokee.sh
SUB_FILES=	pkg-install pkg-message
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CHEROKEE_VARDIR?=	/var
CHEROKEE_LOGDIR?=	${CHEROKEE_VARDIR}/log
CHEROKEE_ACCESSLOG?=	${CHEROKEE_LOGDIR}/cherokee.access
CHEROKEE_ERRORLOG?=	${CHEROKEE_LOGDIR}/cherokee.error

# Adjust this if you need to run Cherokee as a distinct user:group
CHEROKEE_USER=	www
CHEROKEE_GROUP=	www

# This should be ok since 1.0.9, cherokee drops privileges
# after opening logfiles as a security measure
CHEROKEE_LOGFILE_FILEMODE=	0600
CHEROKEE_LOGFILE_USER=	root
CHEROKEE_LOGFILE_GROUP=	wheel

# Directory where to put RRD files, by default
CHEROKEE_RRDDIR=/var/lib/cherokee/graphs

CONFIGURE_ARGS=	--with-wwwroot=${PREFIX}/www/cherokee \
		--localstatedir=${CHEROKEE_VARDIR} \
		--disable-static
DEFCONFS=	cherokee.conf
CONFSUBDIRS=	ssl mods-available mods-enabled sites-available sites-enabled
MAN1=		cget.1 cherokee-config.1 cherokee.1 cherokee-admin.1 cherokee-admin-launcher.1 \
		cherokee-tweak.1 cherokee-worker.1
PORTDOCS=	*

OPTIONS=	IPV6	  "IPv6 support"	on	\
		MYSQL	  "MySQL Database"	off	\
		LDAP	  "LDAP Support"	off	\
		GEOIP	  "GeoIP Support (recommended)"	on	\
		FFMPEG	  "FFMpeg Support"	off	\
		NLS	  "NLS Support"	on	\
		INTPCRE	  "Use Internal PCRE Library"	off	\
		ADMIN	  "Build the Admin Interface"	on	\
		RRDTOOL   "Usage Graphs Support"  off	\
		UWSGI     "uWSGI Support" off

.include <bsd.port.options.mk>

.ifdef WITH_ADMIN
USE_PYTHON=	2.5+
PLIST_SUB+=	ADMIN=""
.else
CONFIGURE_ARGS+=--disable-admin
PLIST_SUB+=	ADMIN="@comment "
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-wwwuser=${CHEROKEE_USER} --with-wwwgroup=${CHEROKEE_GROUP}

.ifdef WITHOUT_IPV6
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.ifdef WITH_MYSQL
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=	--with-mysql=no
PLIST_SUB+=	MYSQL="@comment "
.endif

.ifdef WITH_LDAP
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=yes
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=	--with-ldap=no
PLIST_SUB+=	LDAP="@comment "
.endif

.ifdef WITH_GEOIP
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=	--with-geoip=yes
PLIST_SUB+=	GEOIP=""
.else
CONFIGURE_ARGS+=	--with-geoip=no
PLIST_SUB+=	GEOIP="@comment "
.endif

.ifdef WITH_FFMPEG
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		avutil:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg=yes
.else
CONFIGURE_ARGS+=	--with-ffmpeg=no
.endif

.ifdef WITH_NLS
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.ifdef WITH_INTPCRE
CONFIGURE_ARGS+=	--enable-internal-pcre
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.ifdef WITH_RRDTOOL
RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
.endif

.ifdef WITH_UWSGI
RUN_DEPENDS+=	uwsgi:${PORTSDIR}/www/uwsgi
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|@mkdir_p@|${MKDIR} --|g'
	@${REINPLACE_CMD} -e '/cherokee_replace.*%sysconfdir%/d;/^SUBDIRS/s|doc ||;\
		/^install-data-am/s|install-data-local|install-data-local-config|;\
		/^SUBDIRS/s|windows||'\
		${WRKSRC}/Makefile.in
	@for i in ${BUILD_WRKSRC}/*.sample.pre;do ${SED} -e \
		's:%wwwroot%:${PREFIX}/www/cherokee:g; \
		s:%prefix%:${PREFIX}:g; \
		s:%localstatedir%:/var:g' \
		$$i > $${i%.pre};done

	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/admin/CTK/CTK-run.pre
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/cherokee/cherokee-admin-launcher
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/admin/server.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/admin/upgrade_config.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/cherokee/cherokee-tweak
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/doc/cookbook_dbslayer.html
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/doc/test_images.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/contrib/tracelor.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/gitlog2changelog.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/po/po_stats.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/qa/fcgi.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/qa/run-tests.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/svnlog2changelog.py

post-install:
	@${INSTALL} -d ${CONFSUBDIRS:S|^|${PREFIX}/etc/cherokee/|}
	@for i in ${DEFCONFS};do\
		${INSTALL_DATA} ${WRKSRC}/$$i.sample ${PREFIX}/etc/cherokee/$$i.default;done
	@${INSTALL_DATA} ${WRKSRC}/performance.conf.sample ${PREFIX}/etc/cherokee/cherokee.conf.perf_sample
	@:>${PREFIX}/etc/cherokee/mods-enabled/.empty
	@:>${PREFIX}/etc/cherokee/sites-available/.empty
	@:>${PREFIX}/etc/cherokee/sites-enabled/.empty
	@:>${PREFIX}/etc/cherokee/ssl/.empty
	@for i in `${FIND} ${PREFIX}/etc/cherokee/ -name \*.default`;do\
		if [ ! -f $${i%.default} ];then ${CP} $$i $${i%.default};fi;done
	@for i in `${FIND} ${PREFIX}/etc/cherokee/ -name \*.sample`;do\
		if [ ! -f $${i%.sample} ];then ${CP} $$i $${i%.sample};fi;done

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.ifdef WITH_ADMIN
	@cd ${DATADIR}/admin && ${FIND} . -name "*.py" |\
	${XARGS} ${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py
.endif

	@${SETENV} \
	     CHEROKEE_LOGFILE_FILEMODE=${CHEROKEE_LOGFILE_FILEMODE} \
	     CHEROKEE_LOGFILE_USER=${CHEROKEE_LOGFILE_USER} \
	     CHEROKEE_LOGFILE_GROUP=${CHEROKEE_LOGFILE_GROUP} \
	     CHEROKEE_ERRORLOG=${CHEROKEE_ERRORLOG} \
	     CHEROKEE_ACCESSLOG=${CHEROKEE_ACCESSLOG} \
	     CHEROKEE_WITH_RRDTOOL=${WITH_RRDTOOL} \
	     CHEROKEE_RRDDIR=${CHEROKEE_RRDDIR} \
	     CHEROKEE_RRDDIR_USER=${CHEROKEE_USER} \
	     CHEROKEE_RRDDIR_GROUP=${CHEROKEE_GROUP} \
	     ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${ECHO_MSG} "==============================================================="
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} "==============================================================="

.include <bsd.port.post.mk>
