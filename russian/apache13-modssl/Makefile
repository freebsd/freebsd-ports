# New ports collection makefile for:	Russian Apache + mod_ssl
# Date created:		7 July 2000 1:05 MSD
# Whom:			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	apache+mod_ssl
PORTVERSION=	${VERSION_APACHE}.${VERSION_RA}.${VERSION_MODSSL}
CATEGORIES=	russian www security
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/httpd/ \
		ftp://ftp.rge.com/pub/infosystems/apache/dist/httpd/ \
		ftp://apache.compuex.com/pub/apache/dist/httpd/ \
		ftp://apache.arctic.org/pub/apache/dist/httpd/ \
		ftp://ftp.epix.net/pub/apache/dist/httpd/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/httpd/ \
		ftp://ftp.connectnet.com/pub/www/apache/httpd/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/httpd/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/httpd/ \
		ftp://www3.service.digital.com/apache/dist/httpd/ \
		ftp://galileo.galilei.com/pub/apache/httpd/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/httpd/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/httpd/ \
		ftp://apache.nextpath.com/pub/apache/dist/httpd/ \
		${MASTER_SITES_MODSSL:S/$/:modssl/} \
		${MASTER_SITES_RA:S/$/:rapatches/}

MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
			ftp://ftp.modssl.org/source/ \
			ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/ \
			ftp://ftp.ecrc.net/pub/security/mod_ssl/ \
			ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
			ftp://ftp.ulpgc.es/pub/mod_ssl/ \
			ftp://glock.missouri.edu/pub/mod_ssl/ \
			ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
			ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/

MASTER_SITES_RA=	ftp://ftp.lexa.ru/pub/apache-rus/ \
			ftp://ftp.lexa.ru/pub/apache-rus/old-versions/


DISTNAME=	apache_${VERSION_APACHE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}:modssl \
		patches_${VERSION_APACHE}rusPL${VERSION_RA}.tar.gz:rapatches

MAINTAINER=	lev@serebryakov.spb.ru

USE_OPENSSL=	YES

.include <bsd.port.pre.mk>

LIB_DEPENDS=	mm.11:${PORTSDIR}/devel/mm

VERSION_APACHE=	1.3.26
VERSION_MODSSL=	2.8.10
VERSION_RA=	30.14

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		--suexec-docroot=${PREFIX}/www/data \
		--without-confadjust \
		--enable-shared=remain \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=ssl \
		--disable-shared=ssl \
		--enable-module=define \
		--disable-shared=define \
		--disable-module=auth_dbm

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"${PREFIX}/bin:/bin:/usr/bin\\" \
		-DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(WITH_APACHE_PERF_TUNING) && ${WITH_APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer \
		-fexpensive-optimizations -ffast-math
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		SSL_BASE='SYSTEM' \
		EAPI_MM='SYSTEM' \
		PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8

TYPE=	test
CRT=
KEY=

pre-extract:
.if defined(WITH_SUEXEC)
	@${ECHO} "Be sure to edit suexec specific arguments to configure in the Makefile."
CONFIGURE_ARGS+=--enable-suexec \
		--suexec-caller=nobody \
		--suexec-logfile=/var/log/suexec.log \
		--suexec-uidmin=50000 \
		--suexec-gidmin=60000
MAN8+=		suexec.8
.else
	@${ECHO} "Define WITH_SUEXEC to build with suexec support."
.endif

.if defined(APACHE_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${APACHE_CONFIGURE_ARGS}
.endif

pre-patch:
	@cd ${WRKDIR}/apache_${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying Russian Apache extension" \
	&& ${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/RA-1.3rusPL${VERSION_RA}.patch
	@cd ${WRKDIR} \
	&& tar cf - src conf htdocs | tar xf - -C ${WRKDIR}/apache_${VERSION_APACHE}
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert

post-patch:
	@cd ${WRKSRC} \
	&& find . -type f -name "*.orig" -print | xargs ${RM} -f

post-build:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Dummy Certificate for Server (SnakeOil)" \
	&& ${ECHO_MSG} "      [use 'make certificate' to create a real one]" \
	&& ${MAKE} certificate TYPE=dummy >/dev/null 2>&1

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate TYPE=${TYPE} CRT=${CRT} KEY=${KEY}

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi
.if defined(WITH_SUEXEC)
	@${ECHO_CMD} "sbin/suexec" >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
