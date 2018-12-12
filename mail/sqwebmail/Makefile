# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	sqwebmail
PORTVERSION=	6.0.0
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	SF/courier/webmail/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	CGI Webmail client for Maildirs

BUILD_DEPENDS=	courierauthconfig:security/courier-authlib-base \
		gpg:security/gnupg
RUN_DEPENDS=	courierauthconfig:security/courier-authlib-base \
		gpg:security/gnupg
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libcourier-unicode.so:devel/courier-unicode

CFLAGS:=	-I${LOCALBASE}/include -L${LOCALBASE}/lib ${CFLAGS:S/^[:space:]*//}
CXXFLAGS:=	-I${LOCALBASE}/include ${CXXFLAGS:S/^[:space:]*//}

OPTIONS_DEFINE=	CACHEDIR FAM GDBM GZIP HTTPS HTTPS_LOGIN ISPELL MIMETYPES SENTRENAME CHARSET DOCS
OPTIONS_DEFAULT=	CACHEDIR FAM GZIP SENTRENAME
CACHEDIR_DESC=	Cache logins
FAM_DESC=	Build in fam support for IDLE command
GDBM_DESC=	Use gdbm db instead of system bdb
GZIP_DESC=	Compress messages with gzip
HTTPS_DESC=	Generate https:// URLs for all accesses
HTTPS_LOGIN_DESC=	Generate https:// URLs only for login
MIMETYPES_DESC=	search for a mime.types file
SENTRENAME_DESC=	Periodic rename the Sent folder
CHARSET_DESC=	charsets
FAM_USES=	fam

.include "${.CURDIR}/../../security/courier-authlib/Makefile.opt"

CGIBINDIR?=	www/cgi-bin-dist
CGIBINSUBDIR?=	sqwebmail
WEBDATADIR?=	www/data-dist
WEBDATASUBDIR?=	sqwebmail
IMAGEURL?=	${WEBDATASUBDIR}
RCDIR?=		${PREFIX}/etc/rc.d
CACHEDIR?=	/var/sqwebmail/cache
CACHEOWNER?=	bin
MAILOWN?=	courier
MAILGRP?=	courier

# set WITH_TIMEOUTHARD to something other than 7200 seconds (2hr)
# set WITH_TIMEOUTSOFT to something other than 1200 seconds (20m)
# set WITH_AUTOPURGE to something other than 7 days
# set WITH_MAXPURGE to something other than 90 days
#
# The following settings are in bytes:
# set WITH_MAXMSGSIZE to max size of messages (including attachments)
# set WITH_MAXARGSIZE to max size of a text message (excluding attachments)
# set WITH_MAXFORMARGSIZE to max size of attachments
#
# End of user variables

USES=		compiler:c++11-lang gettext gmake iconv perl5 tar:bzip2
USE_RC_SUBR=	sqwebmail-sqwebmaild
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-cgibindir=${PREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
		--enable-imagedir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR} \
		--localstatedir=/var/sqwebmail \
		--sysconfdir=${PREFIX}/etc/sqwebmail \
		--enable-imageurl=/${IMAGEURL} \
		--with-locking-method=fcntl \
		--with-libintl-prefix=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG} \
		--cache-file=${WRKDIR}/sqwebmail.cache \
		--with-mailuser=${MAILOWN} \
		--with-mailgroup=${MAILGRP} \
		--with-notice=unicode

PLIST_SUB+=	CGIBINDIR=${CGIBINDIR} \
		CGIBINSUBDIR=${CGIBINSUBDIR} \
		WEBDATADIR=${WEBDATADIR} \
		WEBDATASUBDIR=${WEBDATASUBDIR} \
		MAILOWN=${MAILOWN} \
		MAILGRP=${MAILGRP} \
		CACHEDIR=${CACHEDIR} \
		CACHEOWN=${CACHEOWNER}

EXTRA_DOCS=	README README.logindomainlist.html README.pam \
		libs/sqwebmail/ChangeLog \
		libs/maildir/README.maildirquota.txt \
		libs/maildir/README.sharedfolders.txt

.include <bsd.port.pre.mk>

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif

.if ! ${PORT_OPTIONS:MCACHEDIR}
PLIST_SUB+=		CACHE="@comment "
CONFIGURE_ARGS+=	--without-cachedir
.else
PLIST_SUB+=		CACHE=""
CONFIGURE_ARGS+=	--with-cachedir=${CACHEDIR} \
			--with-cacheowner=${CACHEOWNER}
.endif

.if ${PORT_OPTIONS:MHTTPS_LOGIN}
CONFIGURE_ARGS+=	--enable-https=login
.elif ${PORT_OPTIONS:MHTTPS}
CONFIGURE_ARGS+=	--enable-https
.endif

.if ! ${PORT_OPTIONS:MSENTRENAME}
CONFIGURE_ARGS+=	--disable-autorenamesent
.endif

.if ! ${PORT_OPTIONS:MGZIP}
CONFIGURE_ARGS+=	--without-gzip
.endif

.if ${PORT_OPTIONS:MISPELL}
BUILD_DEPENDS+=		${LOCALBASE}/bin/ispell:textproc/aspell-ispell
RUN_DEPENDS+=		${LOCALBASE}/bin/ispell:textproc/aspell-ispell
CONFIGURE_ARGS+=	--with-ispell=${LOCALBASE}/bin/ispell
.else
CONFIGURE_ARGS+=	--without-ispell
.endif

.if ${PORT_OPTIONS:MMIMETYPES}
RUN_DEPENDS+=		${LOCALBASE}/etc/mime.types:misc/mime-support
CONFIGURE_ARGS+=	--enable-mimetypes=${LOCALBASE}/etc
.else
CONFIGURE_ARGS+=	--disable-mimetypes
.endif

.if ${PORT_OPTIONS:MTIMEOUTHARD}
CONFIGURE_ARGS+=	--enable-hardtimeout=${WITH_TIMEOUTHARD}
.endif

.if ${PORT_OPTIONS:MTIMEOUTSOFT}
CONFIGURE_ARGS+=	--enable-softtimeout=${WITH_TIMEOUTSOFT}
.endif

.if ${PORT_OPTIONS:MMAXMSGSIZE}
CONFIGURE_ARGS+=	--with-maxmsgsize=${WITH_MAXMSGSIZE}
.endif

.if ${PORT_OPTIONS:MMAXARGSIZE}
CONFIGURE_ARGS+=	--with-maxargsize=${WITH_MAXARGSIZE}
.endif

.if ${PORT_OPTIONS:MMAXFORMARGSIZE}
CONFIGURE_ARGS+=	--with-maxformargsize=${WITH_MAXFORMARGSIZE}
.endif

.if ${PORT_OPTIONS:MCHARSET}
CONFIGURE_ARGS+=	--enable-unicode
.endif

.if ${PORT_OPTIONS:MAUTOPURGE}
CONFIGURE_ARGS+=	--enable-autopurge=${WITH_AUTOPURGE}
.endif

.if ${PORT_OPTIONS:MMAXPURGE}
CONFIGURE_ARGS+=	--enable-maxpurge=${WITH_MAXPURGE}
.endif

.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=--with-db=gdbm
LIB_DEPENDS+=	libgdbm.so:databases/gdbm
.else
CONFIGURE_ARGS+=--with-db=db
.endif

post-patch:
.if ! ${PORT_OPTIONS:MFAM}
	@${REINPLACE_CMD} -e 's|$$LIBFAM||g; s|HAVE_FAM|DO_NOT_HAVE_FAM|g' \
		${WRKSRC}/libs/maildir/configure
.endif
	@${REINPLACE_CMD} -e 's|LIBPCRE=-lpcre|LIBPCRE="-L${LOCALBASE}/lib -lpcre"|g' \
		${WRKSRC}/libs/maildir/configure

	@${REINPLACE_CMD} -e 's|@echo|echo|g'  ${WRKSRC}/libs/maildir/configure

	@${REINPLACE_CMD} -e 's|-lpcre|-L${LOCALBASE}/lib &|g' \
		${WRKSRC}/libs/sqwebmail/Makefile.in

	@${REINPLACE_CMD} -e 's|\$$(testmaildirfilter_LDADD)|& \$$(LIBPCRE)|g; \
		s|$$(LINK) $$(maildirkw_LDFLAGS)|$$(CXXLINK) $$(maildirkw_LDFLAGS)|' \
		${WRKSRC}/libs/maildir/Makefile.in

	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/libs/liblock/configure

	@${REINPLACE_CMD} -e 's|mkdir -p|${MKDIR}|g' ${WRKSRC}/libs/pcp/configure

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Add the following line to your /etc/crontab to make sure the"
	@${ECHO_MSG} "sqwebmail cache directory gets cleaned up."
	@${ECHO_MSG} "0 * * * * ${CACHEOWNER} ${PREFIX}/share/sqwebmail/cleancache.pl"
	@${ECHO_MSG} ""

post-install:
	@${MV} ${STAGEDIR}/${ETCDIR}/ldapaddressbook.dist ${STAGEDIR}/${ETCDIR}/ldapaddressbook.sample
	@${MV} ${STAGEDIR}/${ETCDIR}/sqwebmaild.dist ${STAGEDIR}/${ETCDIR}/sqwebmaild.sample

.include <bsd.port.post.mk>
