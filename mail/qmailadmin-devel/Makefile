# New ports collection makefile for: qmailadmin
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	qmailadmin
PORTVERSION=	1.2.0
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	CGI program for administering Qmail with vchkpw/vpopmail

BUILD_DEPENDS= \
	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
	autorespond:${PORTSDIR}/mail/autorespond \
	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS= \
	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
	autorespond:${PORTSDIR}/mail/autorespond \
	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

.if defined(WITHOUT_IDX)
BUILD_DEPENDS+=	ezmlm-send:${PORTSDIR}/mail/ezmlm
RUN_DEPENDS+=	ezmlm-send:${PORTSDIR}/mail/ezmlm
.else
BUILD_DEPENDS+=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx
RUN_DEPENDS+=	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx
.endif

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

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

CGIBINDIR?=	www/cgi-bin.default
CGIBINSUBDIR?=	qmailadmin
CGIBINURL?=	/cgi-bin
WEBDATADIR?=	www/data.default
WEBDATASUBDIR?= qmailadmin
WEBDATAURL?=

PLIST_SUB+=	CGIBINDIR="${CGIBINDIR}" CGIBINSUBDIR="${CGIBINSUBDIR}" \
		WEBDATADIR="${WEBDATADIR}" WEBDATASUBDIR="${WEBDATASUBDIR}"

.include <bsd.port.pre.mk>

#
# QMAIL_DIR     - location of qmail directory
#

.if exists(${LOCALBASE}/qmail/bin/qmail-send)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

# End of user-configurable variables

CONFIGURE_ARGS+=	\
	--enable-htmldir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR} \
	--enable-imagedir=${PREFIX}/${WEBDATADIR}/${WEBDATASUBDIR}/images \
	--enable-imageurl=${WEBDATAURL}/${WEBDATASUBDIR}/images \
	--enable-htmllibdir=${DATADIR} \
	--enable-cgibindir=${PREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
	--enable-cgipath=${CGIBINURL}/${CGIBINSUBDIR}/qmailadmin \
	--enable-vpopmaildir=${LOCALBASE}/vpopmail \
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

.include <bsd.port.post.mk>
