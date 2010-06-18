# New ports collection makefile for:	woadaptor
# Date created:				Thu Apr 12 04:43:26 EST 2007
# Whom:					Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME?=	woadaptor
PORTVERSION=	${WONDERVERSION}
CATEGORIES=	www
MASTER_SITES=	#
DISTNAME=	woadaptor-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	WebObjects WebServer Adaptor (Apache Module and CGI)

BROKEN= source code is now in SVN and no-longer in CVS

MAKE_JOBS_UNSAFE=	yes
IGNOREFILES=	${DISTFILES}

USE_BZIP2=	yes
USE_GMAKE=	yes

WWWUSER?=	${WWWOWN}
WWWGROUP?=	${WWWGRP}

SUB_FILES+=	pkg-install pkg-deinstall pkg-message \
		mod-message cgi-message fastcgi-message webobjects.conf-dist \
		FastCGI-apache.conf FastCGI-nginx.conf FastCGI-lighttpd.conf \
		woadaptor.sh
SUB_LIST=	USER=${WWWUSER} GROUP=${WWWGROUP} WODOCROOT=${WODOCROOT_REL}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

CONFLICTS?=	woadaptor-cgi-[0-9]* mod_webobjects-[0-9]*

WONDERREL=	4.0.0
TODAY!=		date "+%Y%m%d"
SNAPDATE=	20071014
WONDERREV=	${SNAPDATE}

.if defined(WITH_WONDERNIGHTLY) || defined(WITH_WONDERCVS)
SNAPDATE=	${TODAY}
MD5_FILE=	""
.endif

WONDERVERSION=	${WONDERREL}.${WONDERREV}
SNAPVERSION=	${WONDERREL}.${SNAPDATE}

XDISTNAME=	woadaptor-${WONDERVERSION}
XDISTFILE=	${DISTDIR}/${XDISTNAME}.tar.bz2
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
WODOCROOT?=	${PREFIX}/www/webobjects
WODOCROOT_REL=	${WODOCROOT:S,^${PREFIX}/,,}

.if !defined(PKGNAMEPREFIX) && !defined(PKGNAMESUFFIX)
OPTIONS=	CGI "Build CGI version" on \
		APACHE "Build Apache module" off \
		FASTCGI "Enable fastcgi support (CGI only)" on
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE)
CONFLICTS?=	mod_webobjects-[0-9]*
.endif

MAKE_ARGS=	OS=FreeBSD ADAPTORS="${ADAPTORS}" LOCALBASE=${LOCALBASE}

.if !defined(WITHOUT_SSL)
MAKE_ARGS+=	USE_SSL="yes"
.endif

.if !defined(WITHOUT_CGI)
CGI_BIN?=	www/cgi-bin
PLIST_SUB+=	CGI_BIN=${CGI_BIN}
SUB_LIST+=	CGI_BIN=${CGI_BIN}
.if !defined(WITHOUT_FASTCGI)
USE_RC_SUBR+=	woadaptor.sh
LIB_DEPENDS+=	fcgi:${PORTSDIR}/www/fcgi
ADAPTORS+=	FastCGI
PLIST_SUB+=	FASTCGI=""
PLIST_SUB+=	CGI="@comment "
SUB_LIST+=	CGIEXT="-fcgi"
.else
ADAPTORS+=	CGI
PLIST_SUB+=	CGI=""
PLIST_SUB+=	FASTCGI="@comment "
SUB_LIST+=	CGIEXT=""
.endif
.else
PLIST_SUB+=	FASTCGI="@comment "
PLIST_SUB+=	CGI="@comment "
.endif

.if defined(WITH_APACHE)
USE_APACHE?=	1.3+

.include "${PORTSDIR}/Mk/bsd.apache.mk"

MAKE_ARGS+=	APXS=${APXS} APACHEINCLUDE_DIR=${APACHEINCLUDEDIR}
APACHECONFDIR=	${APACHEETCDIR}
PLIST_SUB+=	APACHEETCDIR=${APACHEETCDIR} APACHEMODDIR=${APACHEMODDIR}
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} APACHE="" \
		APACHECONFDIR=${APACHECONFDIR} WWWDATA=${WWWDATA}
.if ${APACHE_VERSION} >= 20
APACHECONFDIR=	${APACHEETCDIR}/Includes
.if ${APACHE_VERSION} >= 22
ADAPTORS+=	Apache2.2
APACHE_VER=	2.2
.else
ADAPTORS+=	Apache2
APACHE_VER=	2
.endif
# Apache2.2
.else
# Must be Apache 1.3
.if exists(${APXS})
WITH_MODSSL:=`${APXS} -q CFLAGS 2>/dev/null \
		| ${GREP} DMOD_SSL >/dev/null \
		&& ${ECHO} yes`
.endif
MAKE_ARGS+=	WITH_MODSSL=${WITH_MODSSL}
ADAPTORS+=	Apache
APACHE_VER=
.endif
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
.endif
# WITH_APACHE

.if !defined(WITHOUT_DEBUG)
# this doesn't do anything
MAKE_ARGS+=	DEBUG="yes"
.endif

.if !defined(UID)
UID!=	${ID} -u
.endif

pre-fetch:
.if defined(WITHOUT_CGI) && !defined(WITH_APACHE)
	@${ECHO_MSG} You must select at least one build target
	@${FALSE}
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
do-fetch: build-distfile
.endif

build-distfile:
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${DISTDIR}
	@${RM} -rf ${WRKDIR}/${XDISTNAME}
	@${ECHO_MSG} ">> Building distfile from CVS..."
	cd ${WRKDIR}; \
	    cvs -q -d:pserver:anonymous@wonder.cvs.sourceforge.net:/cvsroot/wonder co \
	    -D ${SNAPDATE} -d ${XDISTNAME} Wonder/Adaptors
	@${FIND} ${WRKDIR}/${XDISTNAME} -name CVS | ${XARGS} ${RM} -rf
	@(cd ${WRKDIR} && ${TAR} cfy ${XDISTFILE} ${XDISTNAME})
	@${RM} -rf ${WRKDIR}/${XDISTNAME}
	@${RMDIR} ${WRKDIR} 2>/dev/null || true
	@${ECHO_MSG} ">> Done. "

do-install:
.if defined(WITH_APACHE)
.if ${APACHE_VERSION} > 21
	@${APXS} -i -a -n WebObjects ${WRKSRC}/Apache${APACHE_VER}/mod_WebObjects.la
.else
	@${APXS} -i -a -n WebObjects ${WRKSRC}/Apache${APACHE_VER}/mod_WebObjects.so
.endif
	@${INSTALL_DATA} ${WRKDIR}/webobjects.conf-dist \
		${PREFIX}/${APACHEETCDIR}
	@if [ ! -e ${PREFIX}/${APACHECONFDIR}/webobjects.conf ]; then \
		${CP} ${WRKDIR}/webobjects.conf-dist \
			${PREFIX}/${APACHECONFDIR}/webobjects.conf; \
	fi
.endif
.if defined(WITH_CGI)
.if !defined(WITHOUT_FASTCGI)
	@${INSTALL_PROGRAM} ${WRKSRC}/FastCGI/WebObjects \
		${PREFIX}/libexec/WebObjects-fcgi
.else
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/CGI/WebObjects ${PREFIX}/libexec/WebObjects
.endif
.endif

post-install:
.if !defined(WITHOUT_FASTCGI)
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/FastCGI-apache.conf ${DATADIR}/apache.conf
	@${INSTALL_DATA} ${WRKDIR}/FastCGI-nginx.conf ${DATADIR}/nginx.conf
	@${INSTALL_DATA} ${WRKDIR}/FastCGI-lighttpd.conf ${DATADIR}/lighttpd.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.if defined(WITH_CGI)
.if !defined(WITHOUT_FASTCGI)
	@${INSTALL_DATA} ${WRKSRC}/FastCGI/README ${DOCSDIR}/README-fcgi
.else
	@${INSTALL_DATA} ${WRKSRC}/CGI/Installation.html ${DOCSDIR}
.endif
.endif
	@${INSTALL_DATA} ${WRKSRC}/example.xml   ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/woadaptor.xml ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/woadaptor.dtd ${DOCSDIR}
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if defined(WITH_APACHE)
	@${CAT} ${WRKDIR}/mod-message >> ${PKGMESSAGE}
.endif
.if defined(WITH_CGI)
.if !defined(WITHOUT_FASTCGI)
	@${CAT} ${WRKDIR}/fastcgi-message >> ${PKGMESSAGE}
.else
	@${CAT} ${WRKDIR}/cgi-message >> ${PKGMESSAGE}
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
