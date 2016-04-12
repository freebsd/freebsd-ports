# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	qmailadmin
PORTVERSION=	1.2.15
PORTREVISION=	7
PORTEPOCH=	2
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION} \
		http://mirror.shatow.net/freebsd/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CGI program for administering Qmail with vchkpw/vpopmail

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autorespond:mail/autorespond \
		${VPOPMAIL_DIR}/lib/libvpopmail.a:mail/vpopmail
RUN_DEPENDS=	autorespond:mail/autorespond \
		${VPOPMAIL_DIR}/lib/libvpopmail.a:mail/vpopmail

USES=		autoreconf gmake qmail:vars

PATCH_SITES+=	http://qmail.jms1.net/vpopmail/:onchange \
		LOCAL/bdrewery/${PORTNAME}/:onchange
PATCHFILES+=	qmailadmin-1.2.12-onchange.3.patch:onchange
PATCH_DIST_STRIP+=	-p1

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	IPAUTH USER_INDEX MODIFY_QUOTA DOMAIN_AUTOFILL \
		IDX IDX_SQL HELP SPAM_DETECTION SPAM_NEEDS_EMAIL \
		CATCHALL TRIVIAL_PASSWORD NOCACHE CRACKLIB
OPTIONS_DEFAULT=IPAUTH IDX_SQL USER_INDEX CATCHALL TRIVIAL_PASSWORD
IPAUTH_DESC=		Check IP address after login
USER_INDEX_DESC=	Enable user index display
MODIFY_QUOTA_DESC=	Allow domain admin to modify quotas
DOMAIN_AUTOFILL_DESC=	Autofill domain on login using hostname
IDX_DESC=		Use ezmlm-idx instead of ezmlm
IDX_SQL_DESC=		Enable MySQL support for ezmlm
HELP_DESC=		Show help links on login page
SPAM_DETECTION_DESC=	Allow users to toggle spam checking
SPAM_NEEDS_EMAIL_DESC=	Append user's email to spam command #'
CATCHALL_DESC=		Enable catch-all accounts
TRIVIAL_PASSWORD_DESC=	Disallow password containing username
NOCACHE_DESC=		Prohibit caching via http headers
CRACKLIB_DESC=		Use cracklib to enforce stronger passwords

CONFIGURE_ARGS+=	\
	--enable-qmaildir=${QMAIL_PREFIX} \
	--enable-htmldir=${WEBPREFIX}/${WEBDATADIR}/${WEBDATASUBDIR} \
	--enable-imagedir=${WEBPREFIX}/${WEBDATADIR}/${WEBDATASUBDIR}/images \
	--enable-imageurl=${WEBDATAURL}/${WEBDATASUBDIR}/images \
	--enable-htmllibdir=${DATADIR} \
	--enable-cgibindir=${WEBPREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
	--enable-cgipath=${CGIBINURL}/${CGIBINSUBDIR}/qmailadmin \
	--enable-vpopmaildir=${VPOPMAIL_DIR} \
	--enable-autoresponder-path=${LOCALBASE}/bin \
	--enable-maxusersperpage=${MAXUSERSPERPAGE} \
	--enable-maxaliasesperpage=${MAXALIASESPERPAGE} \
	--enable-ezmlmdir=${LOCALBASE}/bin

IPAUTH_CONFIGURE_OFF=		--disable-ipauth
USER_INDEX_CONFIGURE_OFF=	--disable-user-index
MODIFY_QUOTA_CONFIGURE_ON=	--enable-modify-quota
DOMAIN_AUTOFILL_CONFIGURE_ON=	--enable-domain-autofill
IDX_SQL_CONFIGURE_OFF=		--disable-ezmlm-mysql
HELP_CONFIGURE_ON=		--enable-help
CATCHALL_CONFIGURE_OFF=		--disable-catchall
TRIVIAL_PASSWORD_CONFIGURE_OFF=	--disable-trivial-password
NOCACHE_CONFIGURE_ON=		--enable-no-cache
SPAM_DETECTION_CONFIGURE_ON=	--enable-modify-spam=y
SPAM_NEEDS_EMAIL_CONFIGURE_ENABLE=	spamcmd-needs-email

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDX}
EXTRA_PATCHES+=		${FILESDIR}/extra-ezmlm-idx7.patch
.endif

.if ${PORT_OPTIONS:MSPAM_DETECTION} && defined(SPAM_COMMAND)
CONFIGURE_ARGS+=	--enable-spam-command="${SPAM_COMMAND}"
.endif

.if ${PORT_OPTIONS:MCRACKLIB}
EXTRA_PATCHES+=		${FILESDIR}/cracklib.patch
BUILD_DEPENDS+=		${LOCALBASE}/include/crack.h:security/cracklib
CONFIGURE_ARGS+=	--enable-cracklib=${LOCALBASE}/libdata/cracklib/pw_dict
CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lcrack
.endif

# vpopmail installation directory
#
# NB: change this with extreme caution!  For instance, if vpopmail is not
# already installed in this directory, building the vpopmail port as
# a dependency will NOT automatically cause it to be installed there!

VPOPMAIL_DIR?=	${LOCALBASE}/vpopmail

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

# Notes and comments:
#
# SPAM_COMMAND		- the command to use to check for spam;
#			  default is "|preline LOCALBASE/bin/maildrop /etc/mailfilter"
#			  do not forget the "|" at the start
# USER_INDEX		- might confuse earlier versions of Internet Explorer
# CGIBINDIR     	- location of your cgi directory
# CGIBINSUBDIR  	- subdirectory to place cgi scripts in
# CGIBINURL     	- location of your cgi directory in a URL
# WEBDATADIR    	- location of your html files
# WEBDATASUBDIR 	- subdirectory to place html files in
# WEBDATAURL    	- location of your html files in a URL
CGIBINDIR?=	www/cgi-bin.default
CGIBINSUBDIR?=	qmailadmin
CGIBINURL?=	/cgi-bin
WEBDATADIR?=	www/data.default
WEBDATASUBDIR?=	qmailadmin
WEBDATAURL?=
MAXUSERSPERPAGE?=	15
MAXALIASESPERPAGE?=	25
WEBPREFIX?=	${PREFIX}

PLIST_SUB+=	CGIBINDIR="${CGIBINDIR}" CGIBINSUBDIR="${CGIBINSUBDIR}" \
		WEBDATADIR="${WEBDATADIR}" WEBDATASUBDIR="${WEBDATASUBDIR}" \
		REAL_PREFIX="${PREFIX}" WEBPREFIX="${WEBPREFIX}"

# End of user-configurable variables

.if empty(PORT_OPTIONS:MIDX)
BUILD_DEPENDS+=	ezmlm-send:mail/ezmlm
RUN_DEPENDS+=	ezmlm-send:mail/ezmlm
.else
BUILD_DEPENDS+=	ezmlm-idx:mail/ezmlm-idx
RUN_DEPENDS+=	ezmlm-idx:mail/ezmlm-idx
.endif

.include <bsd.port.mk>
