# Ports collection makefile for:  nav
# Date created:			  2004-10-19
# Whom:				  Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nav
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Network Administration Visualized

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant \
		${LOCALBASE}/bin/cheetah:${PORTSDIR}/devel/py-cheetah \
		ginstall:${PORTSDIR}/sysutils/coreutils \
		gfind:${PORTSDIR}/misc/findutils \
		ginstall:${PORTSDIR}/sysutils/coreutils \
		${JAVALIBDIR}/snmp.jar:${PORTSDIR}/java/drexelsnmp

.if exists(${LOCALBASE}/jakarta-tomcat4.1/bin/catalina.sh)
TOMCAT_DEPEND=	${LOCALBASE}/jakarta-tomcat4.1:${PORTSDIR}/www/tomcat41
CATALINA_HOME=	${LOCALBASE}/jakarta-tomcat4.1
.elif exists(${LOCALBASE}/jakarta-tomcat4.0.6/bin/catalina.sh)
TOMCAT_DEPEND=	${LOCALBASE}/jakarta-tomcat4.0.6:${PORTSDIR}/www/jakarta-tomcat4
CATALINA_HOME=	${LOCALBASE}/jakarta-tomcat4.0.6
.elif exists(${LOCALBASE}/jakarta-tomcat5.0/bin/catalina.sh)
TOMCAT_DEPEND=	${LOCALBASE}/jakarta-tomcat5.0:${PORTSDIR}/www/jakarta-tomcat5
CATALINA_HOME=	${LOCALBASE}/jakarta-tomcat5.0
.else
TOMCAT_DEPEND=	${LOCALBASE}/tomcat5.5:${PORTSDIR}/www/tomcat55
CATALINA_HOME=	${LOCALBASE}/tomcat5.5
.endif

BUILD_DEPENDS+=		${TOMCAT_DEPEND}

RUN_DEPENDS=	${LOCALBASE}/libexec/apache2/mod_python.so:${PORTSDIR}/www/mod_python3 \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg \
		${SITE_PERL}/${PERL_ARCH}/Pg.pm:${PORTSDIR}/databases/p5-Pg \
		${PYTHON_SITELIBDIR}/rrdtool/_rrdtool.so:${PORTSDIR}/net/py-rrdtool_lgpl \
		${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg \
		${LOCALBASE}/cricket/cricket/collect-subtrees:${PORTSDIR}/net-mgmt/cricket \
		${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc \
		${PYTHON_SITELIBDIR}/forgetSQL.py:${PORTSDIR}/databases/py-forgetsql \
		${PYTHON_SITELIBDIR}/forgetHTML.py:${PORTSDIR}/www/py-forgethtml \
		${PYTHON_SITELIBDIR}/pysnmp/v2c.py:${PORTSDIR}/net-mgmt/py-snmp2 \
		${LOCALBASE}/bin/gammu:${PORTSDIR}/comms/gammu \
		${TOMCAT_DEPEND}

MAKE_ENV+=	CLASSPATH=${CATALINA_HOME}/common/lib/servlet-api.jar
HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_PYTHON=	2.3+
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_APACHE=	yes
WITH_APACHE2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PHP=	yes
WANT_PHP_MOD=	yes
USE_REINPLACE_CMD=	yes
NO_PACKAGE=	Requires manual configuration during build

CONFIGURE_ENV=	INSTALL="${LOCALBASE}/bin/ginstall"
CONFIGURE_ARGS=	--prefix=${PREFIX}/nav ${CONFIGURE_TARGET}
PKGDEINSTALL=	${PKGDIR}/pkg-install

PYENCMISSING=	subsystem/lib-python/src/nav/db/navprofiles.py \
		subsystem/lib-python/src/nav/db/forgotten/manage.py
PYCRONPATH=	subsystem/logger/bin/logengine.py \
		subsystem/messages/bin/maintengine.py \
		subsystem/thresholdMon/thresholdMon.py

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6 or newer
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s@(property name=\"catalina.home\").*@\1 value=\"${CATALINA_HOME}\"/>@" ${WRKSRC}/src/webapps/*/build.xml
	@${REINPLACE_CMD} -e "s@find@gfind@g" ${WRKSRC}/subsystem/alertprofiles/Makefile.in ${WRKSRC}/tools/htpython.sh ${WRKSRC}/subsystem/statTools/cleanrrds.pl
	@${REINPLACE_CMD} -E -e "s@^(CRICKETDIR=).*@\1${LOCALBASE}/cricket@" ${WRKSRC}/subsystem/statTools/cricket.cron
.for f in ${PYENCMISSING}
	@${SCRIPTDIR}/fixpyenc ${WRKSRC}/${f}
.endfor
.for f in ${PYCRONPATH}
	@${REINPLACE_CMD} -E -e "s@/usr/bin/env python@${LOCALBASE}/bin/python@" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E -e "s@^(JAVA_HOME).*@\1 = ${JAVA_HOME}@" \
		${WRKSRC}/doc/conf/nav.conf

# do this in pre-build rather than post-extract or post-patch to avoid
# excessive EXTRACT_DEPENDS.
pre-build:
	${MKDIR} ${WRKSRC}/src/SimpleSnmp/build
	${LN} -fs ${JAVALIBDIR}/snmp.jar ${WRKSRC}/src/SimpleSnmp/build
	${MKDIR} ${WRKSRC}/src/webapps/navAdmin/build
	${LN} -fs ${CATALINA_HOME}/server/lib/catalina-ant.jar ${WRKSRC}/src/webapps/navAdmin/build
	${MKDIR} ${WRKSRC}/src/webapps/vPServer/build
	${LN} -fs ${CATALINA_HOME}/server/lib/catalina-ant.jar ${WRKSRC}/src/webapps/vPServer/build

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${FIND} ${WRKSRC} \( -name '*.bak' -or -name '*.orig' \) -delete

post-install:
	@${INSTALL_DATA} ${FILESDIR}/apache.conf ${PREFIX}/etc/apache2/Includes/nav.conf.sample
	@${CHOWN} -R navcron:nav ${PREFIX}/nav/var
	@LOCALBASE=${LOCALBASE} JAVA_HOME=${JAVA_HOME} ${SH} ${SCRIPTDIR}/navenv w >${WRKSRC}/navenv.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/navenv.sh ${PREFIX}/nav/bin/
	@${ECHO}
	@${ECHO_MSG} "===> You need to set up some environment variables for your nav installation."
	@${ECHO_MSG} "===> To source/set the environment, please add this to /etc/profile or where"
	@${ECHO_MSG} "===> you want it."
	@${ECHO}
	@${ECHO_MSG} ". ${PREFIX}/nav/bin/navenv.sh"
	@${ECHO}
	@${ECHO_MSG} "Now is also a good time to configure username and password for the NAV"
	@${ECHO_MSG} "PostgreSQL database in ${PREFIX}/nav/etc/db.conf. Make sure it is possible to"
	@${ECHO_MSG} "log into it using TCP/IP, check tcpip_socket in postgresql.conf."
	@${ECHO}
	@${ECHO_MSG} "===> Consider using make auto-config. It will auto-configure NAV, setting up"
	@${ECHO_MSG} "===> shell environment and PostgreSQL database."
	@${ECHO}

auto-config:
	@LOCALBASE=${LOCALBASE} PORTSDIR=${PORTSDIR} ${SH} ${SCRIPTDIR}/myautoconf

# TODO
#
# Install more docs?
# Info about Apache/Tomcat setup?
# Fix cricket setup

.include <bsd.port.post.mk>
