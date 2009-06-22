# New ports collection makefile for: qmailadmin
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	qmailadmin
PORTVERSION=	1.2.12
PORTEPOCH=	2
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	CGI program for administering Qmail with vchkpw/vpopmail

# vpopmail installation directory
#
# NB: change this with extreme caution!  For instance, if vpopmail is not
# already installed in this directory, building the vpopmail port as
# a dependency will NOT automatically cause it to be installed there!

VPOPMAIL_DIR?=	${LOCALBASE}/vpopmail

BUILD_DEPENDS=	\
	autorespond:${PORTSDIR}/mail/autorespond \
	${VPOPMAIL_DIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS=	\
	autorespond:${PORTSDIR}/mail/autorespond \
	${VPOPMAIL_DIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

.if defined(WITHOUT_IDX)
BUILD_DEPENDS+=	ezmlm-send:${PORTSDIR}/mail/ezmlm
RUN_DEPENDS+=	ezmlm-send:${PORTSDIR}/mail/ezmlm
.else
BUILD_DEPENDS+=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx
RUN_DEPENDS+=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx
.endif

CONFLICTS=	qmailadmin-devel-1.*

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
WANT_QMAIL=	yes

#
# User-configurable variables
#
# CGIBINDIR     - location of your cgi directory
# CGIBINSUBDIR  - subdirectory to place cgi scripts in
# CGIBINURL     - location of your cgi directory in a URL
# WEBDATADIR    - location of your html files
# WEBDATASUBDIR - subdirectory to place html files in
# WEBDATAURL    - location of your html files in a URL
#
# WITHOUT_IPAUTH	- disable the IP address check after login
# WITHOUT_USER_INDEX	- disable the user index display, which might
#			  confuse earlier versions of Internet Explorer
# WITH_MODIFY_QUOTA	- enable domain admin to modify user quotas
# WITH_DOMAIN_AUTOFILL	- autofill the domain on login page based on the
#			  hostname
# WITHOUT_IDX_SQL	- disable the SQL support for mailing lists
# WITH_HELP		- display help links on login page
#
# WITH_SPAM_DETECTION	- allow users to enable/disable spam checking
# SPAM_COMMAND		- the command to use to check for spam;
#			  default is "|preline /usr/local/bin/maildrop /etc/mailfilter"
#			  do not forget the "|" at the start
# WITH_SPAM_NEEDS_EMAIL	- append the user's e-mail address as the last
#			  argument to the spam command
#

CGIBINDIR?=	www/cgi-bin.default
CGIBINSUBDIR?=	qmailadmin
CGIBINURL?=	/cgi-bin
WEBDATADIR?=	www/data.default
WEBDATASUBDIR?=	qmailadmin
WEBDATAURL?=

PLIST_SUB+=	CGIBINDIR="${CGIBINDIR}" CGIBINSUBDIR="${CGIBINSUBDIR}" \
		WEBDATADIR="${WEBDATADIR}" WEBDATASUBDIR="${WEBDATASUBDIR}"

.include <bsd.port.pre.mk>

# End of user-configurable variables

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
	--enable-ezmlmdir=${LOCALBASE}/bin

.if defined(WITHOUT_IPAUTH)
CONFIGURE_ARGS+=	--disable-ipauth
.endif

.if defined(WITHOUT_USER_INDEX)
CONFIGURE_ARGS+=	--disable-user-index
.endif

.if defined(WITH_MODIFY_QUOTA)
CONFIGURE_ARGS+=	--enable-modify-quota
.endif

.if defined(WITH_DOMAIN_AUTOFILL)
CONFIGURE_ARGS+=	--enable-domain-autofill
.endif

.if defined(WITHOUT_IDX_SQL)
CONFIGURE_ARGS+=	--disable-ezmlm-mysql
.endif

.if defined(WITH_HELP)
CONFIGURE_ARGS+=	--enable-help
.endif

.if defined(WITH_SPAM_DETECTION)
CONFIGURE_ARGS+=	--enable-modify-spam=y
.if defined(SPAM_COMMAND)
CONFIGURE_ARGS+=	--enable-spam-command="${SPAM_COMMAND}"
.endif
.if defined(WITH_SPAM_NEEDS_EMAIL)
CONFIGURE_ARGS+=	--enable-spamcmd-needs-email
.else
CONFIGURE_ARGS+=	--disable-spamcmd-needs-email
.endif
.endif

.include <bsd.port.post.mk>
