# New ports collection makefile for:    apache HTTPD
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=    1.3.24
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=   http://www.apache.org/dist/httpd/ \
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
DISTNAME=	apache_${PORTVERSION}

#PATCH_SITES=    ${MASTER_SITES}
#PATCHFILES=     apache_${PORTVERSION}-fix.diff

MAINTAINER=	ache@freebsd.org

HAS_CONFIGURE=	yes
# += for child ports
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--suexec-docroot=${PREFIX}/www/data \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max

OPTIM=          -DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

#
# Set APACHE_HARD_SERVER_LIMIT env. variable to desired value
#
.if defined(APACHE_HARD_SERVER_LIMIT)
OPTIM+=         -DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
OPTIM+=         -DHARD_SERVER_LIMIT=512
.endif

#
# Set WITH_APACHE_PERF_TUNING env. variable to YES to get maximum performance
#
.if defined(WITH_APACHE_PERF_TUNING) && ${WITH_APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' LD_SHLIB='${CC}'

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/apache.sh \
		> ${WRKSRC}/apache.sh

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
