# New ports collection makefile for: sqwebmail
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	sqwebmail
PORTVERSION=	5.0.0
PORTREVISION=	0
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	CGI Webmail client for Maildirs

BUILD_DEPENDS=	${LOCALBASE}/bin/courierauthconfig:${PORTSDIR}/mail/courier-authlib
RUN_DEPENDS=	${LOCALBASE}/bin/courierauthconfig:${PORTSDIR}/mail/courier-authlib

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

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
# set CACHEOWNER to who you'd like to own the cache files
# set CACHEDIR to where you'd like your cache directory to be
#

CGIBINDIR?=	www/cgi-bin-dist
CGIBINSUBDIR?=	sqwebmail
WEBDATADIR?=	www/data-dist
WEBDATASUBDIR?=	sqwebmail
IMAGEURL?=	${WEBDATASUBDIR}
RCDIR?=		${PREFIX}/etc/rc.d
CACHEDIR?=	${PREFIX}/var/sqwebmail/cache
CACHEOWNER?=	bin

#
# set WITHOUT_CACHEDIR to disable the cache dir
# set WITH_HTTPS to generate https:// URLs for all accesses
# set WITH_HTTPS=login to generate https:// URLs for only password access
# set WITH_ISPELL to provide spell-checking
# set WITH_MIMETYPES to enable the search for a mime.types file
# set WITH_TIMEOUTHARD to something other than 7200 seconds (2hr)
# set WITH_TIMEOUTSOFT to something other than 1200 seconds (20m)
# set WITHOUT_SENTRENAME to turn off periodic renaming of the Sent folder
# set WITHOUT_IMAP if you don't use the Courier IMAP server
# set WITHOUT_GZIP for not using gzip to compress messages
#
# The following settings are in bytes:
# set WITH_MAXMSGSIZE to max size of messages (including attachments)
# set WITH_MAXARGSIZE to max size of a text message (excluding attachments)
# set WITH_MAXFORMARGSIZE to max size of attachments
# 
# set WITH_CHARSET=chset,chset,... to enable charsets.
# Set it to "all" will enable all unicode charset mappings.
# "iconv -l" may give you an idea of some usable character sets, although
# this is not exactly the same as the set which sqwebmail provides.
# Do not forget the template character set and UTF-8. For example, to be
# able to read ISO-8859-15 correctly, you need at least
# WITH_CHARSET=ISO-8859-15,ISO-8859-1,UTF-8

# End of user variables

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-unknown-freebsd${OSREL}
USE_PERL5=	YES
HAS_CONFIGURE=	YES
USE_BZIP2=	YES
USE_REINPLACE=	YES
USE_GETTEXT=	YES
USE_GMAKE=	YES
USE_RC_SUBR=	YES
USE_LIBTOOL_VER=15

CONFIGURE_ARGS=	--enable-cgibindir=${PREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
		--enable-imagedir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR} \
		--localstatedir=${PREFIX}/var/sqwebmail \
		--sysconfdir=${PREFIX}/etc/sqwebmail \
		--mandir=${PREFIX}/man \
		--enable-imageurl=/${IMAGEURL} \
		--with-locking-method=fcntl \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

PLIST_SUB+=	CGIBINDIR=${CGIBINDIR} \
		CGIBINSUBDIR=${CGIBINSUBDIR} \
		WEBDATADIR=${WEBDATADIR} \
		WEBDATASUBDIR=${WEBDATASUBDIR}

.if defined(WITHOUT_CACHEDIR)
PLIST_SUB+=		CACHE="@comment "
CONFIGURE_ARGS+=	--without-cachedir
.else
PLIST_SUB+=		CACHE=""
CONFIGURE_ARGS+=	--with-cachedir=${CACHEDIR} \
			--with-cacheowner=${CACHEOWNER}
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

.if defined(WITHOUT_GZIP)
CONFIGURE_ARGS+=	--without-gzip
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

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN1=		maildirmake.1
MAN8=		deliverquota.8

EXTRA_DOCS=	README README.logindomainlist.html README.pam sqwebmail/ChangeLog \
		maildir/README.maildirquota.txt maildir/README.sharedfolders.txt

post-patch:
	@${REINPLACE_CMD} -e 's|^case x$$lockmethod in|${TEST} \&\& &|g' \
		${WRKSRC}/liblock/configure

	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -rpath=:${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/sqwebmail/Makefile.in

	@${REINPLACE_CMD} -e 's|mkdir -p|${MKDIR}|g' ${WRKSRC}/pcp/configure

	@${REINPLACE_CMD} -e 's|@LIBTOOL@|${LIBTOOL}| ; \
		s|$$(SHELL) $$(MKINSTALLDIRS)|$$(MKINSTALLDIRS)|' \
		${WRKSRC}/pcp/intl/Makefile.in

post-install:
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/sqwebmail-sqwebmaild.sh > ${WRKDIR}/sqwebmail-sqwebmaild.sh
	${INSTALL_SCRIPT} ${WRKDIR}/sqwebmail-sqwebmaild.sh ${RCDIR}/sqwebmail-sqwebmaild.sh

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif
	cd ${WRKSRC} && ( ${MAKE} install-configure ; cd - )

	@${ECHO_MSG} ""
	@${ECHO_MSG} "Add the following line to your /etc/crontab to make shure the"
	@${ECHO_MSG} "sqwebmail cache directory gets cleaned up."
	@${ECHO_MSG} "0 * * * * ${CACHEOWNER} ${PREFIX}/share/sqwebmail/cleancache.pl"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
