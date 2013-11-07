# Created by: silence <oksala@videotron.ca>
# $FreeBSD$

PORTNAME=	cherokee
PORTVERSION=	1.2.101
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=cherokee/1.2/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely fast and flexible web server

BROKEN=		Does not configure

USES=		gettext gmake pathfix pkgconfig
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	cherokee
SUB_FILES=	pkg-install pkg-message
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

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

OPTIONS_DEFINE=	IPV6 MYSQL LDAP GEOIP FFMPEG NLS INTPCRE ADMIN ADMIN RRDTOOL UWSGI DOCS
OPTIONS_DEFAULT=IPV6 GEOIP ADMIN
ADMIN_DESC=	Build the Admin Interface
INTPCRE_DESC=	Use internal PCRE library
RRDTOOL_DESC=	Usage graphs support
UWSGI_DESC=	uWSGI support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MADMIN}
USE_PYTHON=	2.5+
PLIST_SUB+=	ADMIN=""
.else
CONFIGURE_ARGS+=--disable-admin
PLIST_SUB+=	ADMIN="@comment "
.endif

CONFIGURE_ARGS+=--with-wwwuser=${CHEROKEE_USER} --with-wwwgroup=${CHEROKEE_GROUP}

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--with-mysql=no
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=yes
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--with-ldap=no
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=--with-geoip=yes
PLIST_SUB+=	GEOIP=""
.else
CONFIGURE_ARGS+=--with-geoip=no
PLIST_SUB+=	GEOIP="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		avutil:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--with-ffmpeg=yes
.else
CONFIGURE_ARGS+=--with-ffmpeg=no
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MINTPCRE}
CONFIGURE_ARGS+=--enable-internal-pcre
.else
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.endif

.if ${PORT_OPTIONS:MRRDTOOL}
RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
.endif

.if ${PORT_OPTIONS:MUWSGI}
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
		${WRKSRC}/po/po_stats.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/qa/fcgi.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|/usr/local/bin/python|' \
		${WRKSRC}/qa/run-tests.py

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

.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MADMIN}
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

.include <bsd.port.mk>
