# New ports collection makefile for: qmailadmin
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	qmailadmin
PORTVERSION=	1.2.15
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	CGI program for administering Qmail with vchkpw/vpopmail

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	\
	autorespond:${PORTSDIR}/mail/autorespond \
	${VPOPMAIL_DIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS=	\
	autorespond:${PORTSDIR}/mail/autorespond \
	${VPOPMAIL_DIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

CONFLICTS=	qmailadmin-devel-1.*

OPTIONS_DEFINE=	IPAUTH USER_INDEX MODIFY_QUOTA DOMAIN_AUTOFILL \
		IDX IDX_SQL HELP SPAM_DETECTION SPAM_NEEDS_EMAIL \
		CATCHALL TRIVIAL_PASSWORD NOCACHE
OPTIONS_DEFAULT=IPAUTH IDX_SQL USER_INDEX CATCHALL TRIVIAL_PASSWORD
IPAUTH_DESC=		Check IP address after login
USER_INDEX_DESC=	Enable user index display
MODIFY_QUOTA_DESC=	Allow domain admin to modify quotas
DOMAIN_AUTOFILL_DESC=	Autofill domain on login using hostname
IDX_DESC=		Use ezmlm-idx instead of ezmlm
IDX_SQL_DESC=		Enable MySQL support for ezmlm
HELP_DESC=		Show help links on login page
SPAM_DETECTION_DESC=	Allow users to toggle spam checking
SPAM_NEEDS_EMAIL_DESC=	Append user's email to spam command
CATCHALL_DESC=		Enable catch-all accounts
TRIVIAL_PASSWORD_DESC=	Disallow password containing username
NOCACHE_DESC=		Prohibit caching via http headers

.include <bsd.port.options.mk>

# vpopmail installation directory
#
# NB: change this with extreme caution!  For instance, if vpopmail is not
# already installed in this directory, building the vpopmail port as
# a dependency will NOT automatically cause it to be installed there!

VPOPMAIL_DIR?=	${LOCALBASE}/vpopmail

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
WANT_QMAIL=	yes

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

PLIST_SUB+=	CGIBINDIR="${CGIBINDIR}" CGIBINSUBDIR="${CGIBINSUBDIR}" \
		WEBDATADIR="${WEBDATADIR}" WEBDATASUBDIR="${WEBDATASUBDIR}"

# End of user-configurable variables

.if empty(PORT_OPTIONS:MIDX)
BUILD_DEPENDS+=	ezmlm-send:${PORTSDIR}/mail/ezmlm
RUN_DEPENDS+=	ezmlm-send:${PORTSDIR}/mail/ezmlm
.else
BUILD_DEPENDS+=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx
RUN_DEPENDS+=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx
.endif

CONFIGURE_ARGS+=	\
	--enable-qmaildir=${QMAIL_PREFIX} \
	--enable-htmldir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR} \
	--enable-imagedir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR}/images \
	--enable-imageurl=${WEBDATAURL}/${WEBDATASUBDIR}/images \
	--enable-htmllibdir=${DATADIR} \
	--enable-cgibindir=${PREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
	--enable-cgipath=${CGIBINURL}/${CGIBINSUBDIR}/qmailadmin \
	--enable-vpopmaildir=${VPOPMAIL_DIR} \
	--enable-autoresponder-path=${LOCALBASE}/bin \
	--enable-maxusersperpage=${MAXUSERSPERPAGE} \
	--enable-maxaliasesperpage=${MAXALIASESPERPAGE} \
	--enable-ezmlmdir=${LOCALBASE}/bin

.if empty(PORT_OPTIONS:MIPAUTH)
CONFIGURE_ARGS+=	--disable-ipauth
.endif

.if empty(PORT_OPTIONS:MUSER_INDEX)
CONFIGURE_ARGS+=	--disable-user-index
.endif

.if ${PORT_OPTIONS:MMODIFY_QUOTA}
CONFIGURE_ARGS+=	--enable-modify-quota
.endif

.if ${PORT_OPTIONS:MDOMAIN_AUTOFILL}
CONFIGURE_ARGS+=	--enable-domain-autofill
.endif

.if empty(PORT_OPTIONS:MIDX_SQL)
CONFIGURE_ARGS+=	--disable-ezmlm-mysql
.endif

.if ${PORT_OPTIONS:MHELP}
CONFIGURE_ARGS+=	--enable-help
.endif

.if ${PORT_OPTIONS:MSPAM_DETECTION}
CONFIGURE_ARGS+=	--enable-modify-spam=y
.if defined(SPAM_COMMAND)
CONFIGURE_ARGS+=	--enable-spam-command="${SPAM_COMMAND}"
.endif
.if ${PORT_OPTIONS:MSPAM_NEEDS_EMAIL}
CONFIGURE_ARGS+=	--enable-spamcmd-needs-email
.else
CONFIGURE_ARGS+=	--disable-spamcmd-needs-email
.endif
.endif

.if empty(PORT_OPTIONS:MCATCHALL)
CONFIGURE_ARGS+=	--disable-catchall
.endif

.if empty(PORT_OPTIONS:MTRIVIAL_PASSWORD)
CONFIGURE_ARGS+=	--disable-trivial-password
.endif

.if ${PORT_OPTIONS:MNOCACHE}
CONFIGURE_ARGS+=	--enable-no-cache
.endif

.include <bsd.port.mk>
