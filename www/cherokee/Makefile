# Created by: silence <oksala@videotron.ca>
# $FreeBSD$

PORTNAME=	cherokee
PORTVERSION=	1.2.104
DISTVERSIONPREFIX=	v
PORTREVISION=	9
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and flexible web server

LICENSE=	GPLv2

BROKEN_FreeBSD_12=	fails to configure: Unable to detect data struct is used by crypt_r
BROKEN_FreeBSD_13=	fails to configure: Unable to detect data struct is used by crypt_r

USE_GITHUB=	yes
GH_PROJECT=	webserver

USES=		autoreconf cpe gettext gmake libtool pathfix pkgconfig \
		shebangfix ssl
SHEBANG_FILES=	admin/CTK/CTK-run.pre admin/server.py \
		admin/upgrade_config.py cherokee/cherokee-admin-launcher \
		cherokee/cherokee-tweak contrib/tracelor.py \
		doc/build/asciidoc.py doc/cookbook_dbslayer.txt \
		doc/test_images.py doc/test_links.py \
		po/admin/generate_POTFILESin.py po/po_stats.py \
		qa/fcgi.py qa/run-tests.py
USE_RC_SUBR=	cherokee
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--localstatedir=${CHEROKEE_VARDIR} \
		--without-php \
		--with-geoip=no \
		--with-python=${PYTHON_CMD} \
		--with-wwwroot=${WWWDIR} \
		--with-wwwuser=${CHEROKEE_USER} \
		--with-wwwgroup=${CHEROKEE_GROUP}
MAKE_ARGS=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPE_VENDOR=	cherokee-project

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

SUB_FILES=	pkg-install pkg-message

CHEROKEE_VARDIR?=	/var

# Adjust this if you need to run Cherokee as a distinct user:group
CHEROKEE_USER=		www
CHEROKEE_GROUP=		www

OPTIONS_DEFINE=		ADMIN DOCS FFMPEG INTPCRE IPV6 LDAP MYSQL \
			RRDTOOL UWSGI
OPTIONS_DEFAULT=	ADMIN
OPTIONS_SUB=		yes

ADMIN_DESC=		Build the Admin Interface
ADMIN_USES=		python:2.7
ADMIN_USES_OFF=		python:2.7,build 
ADMIN_CONFIGURE_OFF=	--disable-admin
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--with-ffmpeg=yes
FFMPEG_CONFIGURE_OFF=	--with-ffmpeg=no
INTPCRE_DESC=		Use internal PCRE library
INTPCRE_LIB_DEPENDS_OFF=libpcre.so:devel/pcre
INTPCRE_CONFIGURE_ON=	--enable-internal-pcre
IPV6_CONFIGURE_OFF=	--disable-ipv6
LDAP_USE=		openldap=yes
LDAP_CONFIGURE_ON=	--with-ldap=yes
LDAP_CONFIGURE_OFF=	--with-ldap=no
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=yes
MYSQL_CONFIGURE_OFF=	--with-mysql=no
RRDTOOL_DESC=		Usage graphs support
RRDTOOL_RUN_DEPENDS=	rrdtool:databases/rrdtool
UWSGI_DESC=		uWSGI support
UWSGI_RUN_DEPENDS=	uwsgi:www/uwsgi

.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKSRC}/INSTALL

pre-configure:
	@(cd ${WRKSRC}/po/admin && ${PYTHON_CMD} generate_POTFILESin.py \
		> POTFILES.in)

post-install:
.for i in mods-available mods-enabled sites-available sites-enabled ssl
	@${MKDIR} ${STAGEDIR}${ETCDIR}/${i}
	@${ECHO_CMD} -n > ${STAGEDIR}${ETCDIR}/${i}/.empty
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} cherokee.conf.sample \
		${STAGEDIR}${ETCDIR}/cherokee.conf.sample)
	(cd ${WRKSRC} && ${INSTALL_DATA} performance.conf.sample \
		${STAGEDIR}${ETCDIR}/cherokee.conf.perf_sample)
.if ${PORT_OPTIONS:MADMIN}
	(cd ${WRKSRC} && ${INSTALL_DATA} cherokee.conf.sample \
		${STAGEDIR}${DATADIR}/admin)
	(cd ${WRKSRC} && ${INSTALL_DATA} performance.conf.sample \
		${STAGEDIR}${DATADIR}/admin)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${DATADIR}/admin -f ${DATADIR_REL}/admin)
.endif

.include <bsd.port.mk>
