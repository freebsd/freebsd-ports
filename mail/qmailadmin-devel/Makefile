# New ports collection makefile for: qmailadmin
# Date created:		23 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	qmailadmin
PORTVERSION=	0.42
CATEGORIES=	mail www
MASTER_SITES=	http://www.inter7.com/qmailadmin/

MAINTAINER=	nbm@FreeBSD.org

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

CGIBINDIR?=	${PREFIX}/www/cgi-bin.default
CGIBINSUBDIR?=	qmailadmin
CGIBINURL?=	cgi-bin
WEBDATADIR?=	${PREFIX}/www/data.default
WEBDATASUBDIR?=

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
	--enable-htmldir=${WEBDATADIR}/${WEBDATASUBDIR} \
	--enable-cgibindir=${CGIBINDIR}/${CGIBINSUBDIR} \
	--with-htmllibdir=${PREFIX}/share/qmailadmin \
	--enable-cgipath=/${CGIBINURL}/${CGIBINSUBDIR}/qmailadmin \
	--enable-ezmlmidx=y

pre-install:
	@${MKDIR} ${PREFIX}/share/qmailadmin/html

.include <bsd.port.mk>
