# New ports collection makefile for:    apache HTTPD
# Date created:         Sat Apr 10 22:30:36 EEST 1999
# Whom:                 vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	1.3.23
CATEGORIES=	russian www
MASTER_SITES=   http://httpd.apache.org/dist/httpd/ \
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
		ftp://apache.nextpath.com/pub/apache/dist/httpd/
DISTNAME=	${PORTNAME}_${PORTVERSION}

PATCH_SITES=	ftp://ftp.lexa.ru/pub/apache-rus/ \
		ftp://ftp.lexa.ru/pub/apache-rus/old-versions/
PATCHFILES=	patches_${PORTVERSION}rusPL${RA_VERSION}.tar.gz

MAINTAINER=	lev@serebryakov.spb.ru

RA_VERSION=	30.10
Y2K=		http://www.apache.org/docs/misc/FAQ.html#year2000

#
# Small hack for alternate processing patchfiles
#
GZCAT=sh -c 'tar -zxf $$0 -C ${WRKSRC};${CAT} ${WRKSRC}/RA-1.3rusPL${RA_VERSION}.patch'

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		 --prefix=${PREFIX} \
		 --server-gid=nogroup \
		 --with-perl=${PERL} \
		 --with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		 --suexec-docroot=${PREFIX}/www/data \
		 --without-confadjust \
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --disable-module=auth_dbm

OPTIM=-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}'

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8

pre-install:
	@if [ -f ${WRKSRC}/htdocs/index.html.orig ]; then \
		${RM} ${WRKSRC}/htdocs/index.html.orig; \
	fi

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
