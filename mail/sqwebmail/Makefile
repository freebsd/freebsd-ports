# New ports collection makefile for: sqwebmail
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	sqwebmail
PORTVERSION=	3.3.7
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= courier

MAINTAINER=	nbm@FreeBSD.org

#
# User-serviceable variables
#
# [ There's no need to add trailing ``/''s ]
#
# set CGIBINDIR to where you'd like the cgi to be placed
# set CGIBINSUBDIR to subdirectory of CGIBINDIR, if necessary
# set WEBDATADIR to where you'd like web pages to be placed
# set WEBDATASUBDIR to where you'd like web pages to be placed
# set IMAGEURL to where on the web server URL the images are found
#

CGIBINDIR?=	${PREFIX}/www/cgi-bin.default
CGIBINSUBDIR?=	sqwebmail
WEBDATADIR?=	${PREFIX}/www/data.default
WEBDATASUBDIR?=	sqwebmail
IMAGEURL?=	${WEBDATASUBDIR}

#
# set WITHOUT_CACHEDIR to disable the cache dir (can't set it with WITH_LDAP)
# set CACHEOWNER to who you'd like to own the cache files
# set CACHEDIR to where you'd like your cache directory to be
# set WITH_LDAP for LDAP authentication and addressbook support
# set WITH_VCHKPW for vpopmail authentication
# set WITH_ISPELL to provide spell-checking
# set WITH_MIMETYPES to enable the search for a mime.types file
# set WITH_TIMEOUTHARD to something other than 7200 seconds (2hr)
# set WITH_TIMEOUTSOFT to something other than 1200 seconds (20m)
# set VCHKPW to the home of the vpopmail user, if necessary
#

CACHEDIR?=	/var/sqwebmail/cache
CACHEOWNER?=	bin
VCHKPWLOC?=	${LOCALBASE}/vpopmail

# End of user variables

USE_PERL5=	yes
HAS_CONFIGURE=	YES

CONFIGURE_ARGS= \
	--enable-cgibindir=${CGIBINDIR}/${CGIBINSUBDIR} \
	--enable-imagedir=${WEBDATADIR}/${WEBDATASUBDIR} \
	--without-authmysql \
	--libexecdir=${PREFIX}/libexec/sqwebmail \
	--mandir=${PREFIX}/share/sqwebmail/man \
	--prefix=${PREFIX}/share/sqwebmail \
	--enable-imageurl=/${IMAGEURL}/

.if defined(WITHOUT_CACHEDIR)
PLIST_SUB+=		CACHE="@comment "
CONFIGURE_ARGS+=	--without-cachedir
.else
PLIST_SUB+=		CACHE=""
CONFIGURE_ARGS+=	--with-cachedir=${CACHEDIR} \
			--with-cacheowner=${CACHEOWNER}
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=		ldap.1:${PORTSDIR}/net/openldap
CONFIGURE_ARGS+=	--with-authldap
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--without-authldap
.endif

.if defined(WITH_VCHKPW)
BUILD_DEPENDS+= ${VCHKPWLOC}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS+=	${VCHKPWLOC}/bin/vchkpw:${PORTSDIR}/mail/vpopmail

CONFIGURE_ARGS+=	--with-authvchkpw
PLIST_SUB+=		VPOPMAILFLAG=""
.else
CONFIGURE_ARGS+=	--without-authvchkpw
PLIST_SUB+=		VPOPMAILFLAG="@comment "
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-authmysql
PLIST_SUB+=		MYSQLFLAG=""
.else
CONFIGURE_ARGS+=	--without-authmysql
PLIST_SUB+=		MYSQLFLAG="@comment "
.endif

.if defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--with-authpgsql
PLIST_SUB+=		PGSQLFLAG=""
.else
CONFIGURE_ARGS+=	--without-authpgsql
PLIST_SUB+=		PGSQLFLAG="@comment "
.endif

.if defined(WITH_ISPELL)
BUILD_DEPENDS+=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell

CONFIGURE_ARGS+=	--with-ispell=${LOCALBASE}/bin/ispell
.else
CONFIGURE_ARGS+=	--without-ispell
.endif

.if !defined(WITH_MIMETYPES)
CONFIGURE_ARGS+=	--disable-mimetypes
.endif

.if defined(WITH_TIMEOUTHARD)
CONFIGURE_ARGS+=	--enable-hardtimeout=${WITH_TIMEOUTHARD}
.endif

.if defined(WITH_TIMEOUTSOFT)
CONFIGURE_ARGS+=	--enable-softtimeout=${WITH_TIMEOUTSOFT}
.endif

MANPREFIX=	${PREFIX}/share/sqwebmail
MAN1=		maildirmake.1
MAN7=		authlib.7
MAN8=		deliverquota.8 makeuserdb.8 userdb.8 userdbpw.8

MLINKS=		authlib.7 authcram.7 \
		authlib.7 authdaemon.7 \
		authlib.7 authdaemond.7 \
		authlib.7 authldap.7 \
		authlib.7 authpam.7 \
		authlib.7 authpwd.7 \
		authlib.7 authshadow.7 \
		authlib.7 authuserdb.7 \
		authlib.7 authvchkpw.7 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

CONFIGURE_ARGS+=	${CONFIGURE_TARGET}

.include <bsd.port.mk>
