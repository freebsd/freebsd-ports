# New ports collection makefile for: sqwebmail
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	sqwebmail
PORTVERSION=	4.0.3
PORTREVISION=	0
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	CGI Webmail client for Maildirs

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

CGIBINDIR?=	www/cgi-bin-dist
CGIBINSUBDIR?=	sqwebmail
WEBDATADIR?=	www/data-dist
WEBDATASUBDIR?=	sqwebmail
IMAGEURL?=	${WEBDATASUBDIR}

#
# set WITHOUT_CACHEDIR to disable the cache dir (can't set it with WITH_LDAP)
# set WITHOUT_AUTHDAEMON to disable the usage of authdaemond
# set CACHEOWNER to who you'd like to own the cache files
# set CACHEDIR to where you'd like your cache directory to be
# set WITH_LDAP for LDAP authentication and addressbook support
# set WITH_HTTPS to generate https:// URLs for all accesses
# set WITH_HTTPS=login to generate https:// URLs for only password access
# set WITH_VCHKPW for vpopmail authentication
# set WITH_ISPELL to provide spell-checking
# set WITH_MIMETYPES to enable the search for a mime.types file
# set WITH_TIMEOUTHARD to something other than 7200 seconds (2hr)
# set WITH_TIMEOUTSOFT to something other than 1200 seconds (20m)
# set WITHOUT_SENTRENAME to turn off periodic renaming of the Sent folder
# set WITHOUT_IMAP if you don't use the Courier IMAP server
# set VCHKPW to the home of the vpopmail user, if necessary
#
# The following settings are in bytes:
# set WITH_MAXMSGSIZE to max size of messages (including attachments)
# set WITH_MAXARGSIZE to max size of a text message (excluding attachments)
# set WITH_MAXFORMARGSIZE to max size of attachments
# 
# set WITH_CHARSET=chset,chset,... to enable charsets.
# Set it to "all" will enable all unicode charset mappings.
# For available charsets just type "iconv -l"

CACHEDIR?=	/var/sqwebmail/cache
CACHEOWNER?=	bin
VCHKPWLOC?=	${LOCALBASE}/vpopmail

# End of user variables

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-unknown-freebsd${OSREL}
USE_PERL5=	YES
HAS_CONFIGURE=	YES
USE_BZIP2=	YES
USE_REINPLACE=	YES

CONFIGURE_ARGS=	\
	--enable-cgibindir=${PREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
	--enable-imagedir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR} \
	--libexecdir=${PREFIX}/libexec/sqwebmail \
	--mandir=${PREFIX}/man \
	--prefix=${PREFIX}/share/sqwebmail \
	--enable-imageurl=/${IMAGEURL} \
	--with-locking-method=fcntl \
	--with-libintl-prefix=${LOCALBASE} \
	--with-libiconv-prefix=${LOCALBASE}

PLIST_SUB+=	CGIBINDIR=${CGIBINDIR} CGIBINSUBDIR=${CGIBINSUBDIR} WEBDATADIR=${WEBDATADIR} WEBDATASUBDIR=${WEBDATASUBDIR}

.if defined(WITHOUT_CACHEDIR)
PLIST_SUB+=		CACHE="@comment "
CONFIGURE_ARGS+=	--without-cachedir
.else
PLIST_SUB+=		CACHE=""
CONFIGURE_ARGS+=	--with-cachedir=${CACHEDIR} \
			--with-cacheowner=${CACHEOWNER}

.endif
.if !defined(WITHOUT_AUTHDAEMON)
CONFIGURE_ARGS+=	--with-authdaemon
PLIST_SUB+=		AUTHDFLAG=""
.else
CONFIGURE_ARGS+=	--without-authdaemon
PLIST_SUB+=		AUTHDFLAG="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-authldap
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB+=		LDAPFLAG=""
.else
CONFIGURE_ARGS+=	--without-authldap
PLIST_SUB+=		LDAPFLAG="@comment "
.endif

.if defined(WITH_VCHKPW)
BUILD_DEPENDS+=	${VCHKPWLOC}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS+=	${VCHKPWLOC}/bin/vchkpw:${PORTSDIR}/mail/vpopmail

CONFIGURE_ARGS+=	--with-authvchkpw
PLIST_SUB+=		VPOPMAILFLAG=""
.else
CONFIGURE_ARGS+=	--without-authvchkpw
PLIST_SUB+=		VPOPMAILFLAG="@comment "
.endif

.if defined(WITH_HTTPS)
.if ${WITH_HTTPS} == "login"
CONFIGURE_ARGS+=	--enable-https=login
.else
CONFIGURE_ARGS+=	--enable-https
.endif
.endif

.if defined(WITHOUT_SENTRENAME)
CONFIGURE_ARGS+=	--disable-autorenamesent
.endif

.if defined(WITHOUT_IMAP)
CONFIGURE_ARGS+=	--disable-utf7-folder-encoding
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

.if defined(WITH_MAXMSGSIZE)
CONFIGURE_ARGS+=	--with-maxmsgsize=${WITH_MAXMSGSIZE}
.endif

.if defined(WITH_MAXARGSIZE)
CONFIGURE_ARGS+=	--with-maxargsize=${WITH_MAXARGSIZE}
.endif

.if defined(WITH_MAXFORMARGSIZE)
CONFIGURE_ARGS+=	--with-maxformargsize=${WITH_MAXFORMARGSIZE}
.endif

.if defined(WITH_CHARSET)
.if ${WITH_CHARSET:U} == ALL
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--enable-unicode=${WITH_CHARSET}
.endif
.endif

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
		authlib.7 authmysql.7 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

CONFIGURE_ARGS+=	${CONFIGURE_TARGET}

post-patch:
	@${REINPLACE_CMD} -e 's|^@INSTALLAUTHMODULES@$$|& @AUTHMODULES@|' \
		${WRKSRC}/authlib/installlist.in

	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/liblock/configure

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/sqwebmail-sqwebmaild.sh \
		${PREFIX}/etc/rc.d/
.if !defined(WITHOUT_AUTHDAEMON)
	${INSTALL_SCRIPT} ${FILESDIR}/sqwebmail-authdaemond.sh \
		${PREFIX}/etc/rc.d/
.endif

.include <bsd.port.mk>
