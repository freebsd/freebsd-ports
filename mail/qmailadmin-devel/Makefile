# New ports collection makefile for: qmailadmin
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	qmailadmin
PORTVERSION=	1.0.6
CATEGORIES=	mail www
MASTER_SITES=	http://www.inter7.com/qmailadmin/

MAINTAINER=	roam@FreeBSD.org

BUILD_DEPENDS= \
	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
	autorespond:${PORTSDIR}/mail/autorespond \
	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS= \
	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
	autorespond:${PORTSDIR}/mail/autorespond \
	ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

#
# User-configurable variables
#
# CGIBINDIR     - location of your cgi directory
# CGIBINSUBDIR  - subdirectory to place cgi scripts in
# CGIBINURL     - location of your cgi directory in a URL
# WEBDATADIR    - location of your html files
# WEBDATASUBDIR - subdirectory to place html files in (not working yet)
#
# WITHOUT_IPAUTH	- disable the IP address check after login
# WITHOUT_USER_INDEX	- disable the user index display, which might
#			  confuse earlier versions of Internet Explorer
#

CGIBINDIR?=	www/cgi-bin.default
CGIBINSUBDIR?=	qmailadmin
CGIBINURL?=	cgi-bin
WEBDATADIR?=	www/data.default
WEBDATASUBDIR?=

# I'm working on this..
.if ${WEBDATASUBDIR} != ""
BROKEN=	do not set WEBDATASUBDIR: qmailadmin is a bit buggy in that respect
.endif

PLIST_SUB+=	CGIBINDIR="${CGIBINDIR}" CGIBINSUBDIR="${CGIBINSUBDIR}" \
		WEBDATADIR="${WEBDATADIR}" WEBDATASUBDIR="${WEBDATASUBDIR}"

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
	--enable-cgibindir=${PREFIX}/${CGIBINDIR}/${CGIBINSUBDIR} \
	--with-htmllibdir=${PREFIX}/share/qmailadmin \
	--enable-cgipath=/${CGIBINURL}/${CGIBINSUBDIR}/qmailadmin \
	--enable-ezmlmidx=y

.if defined(WITHOUT_IPAUTH)
CONFIGURE_ARGS+=	--enable-ipauth=n
.endif

.if defined(WITHOUT_USER_INDEX)
CONFIGURE_ARGS+=	--enable-user-index=n
.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/qmailadmin/html

.include <bsd.port.mk>
