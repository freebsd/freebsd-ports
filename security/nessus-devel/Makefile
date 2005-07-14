# New ports collection makefile for: 	nessus-devel
# Date created:		27 Oct 2001
# Whom:			Udo Schweigert <udo.schweigert@siemens.com>
#
# $FreeBSD$
#
# If you want to only have the command-line client even if gtk is already
# installed define one of these:
#  WITHOUT_GNOME
#  WITHOUT_GTK
#  WITHOUT_NESSUS_GTK

PORTNAME=	nessus-devel
PORTVERSION=	2.3.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/experimental/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/experimental/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/experimental/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/experimental/nessus-${PORTVERSION}/src/ \
		ftp://ftp.au.nessus.org/pub/nessus/experimental/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/experimental/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-core-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	A security scanner: looks for vulnerabilities in a given network

CONFLICTS=	nessus-[0-9]* nessus-gtk-[0-9]* nessus-gtk2-[0-9]*
LIB_DEPENDS=	nasl.5:${PORTSDIR}/security/nessus-libnasl-devel

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall.sh

USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
USE_REINPLACE=	YES
USE_RC_SUBR=	YES
WANT_GNOME=	yes
.if defined(WITHOUT_NESSUS_GTK) || defined(WITHOUT_GTK)
WITHOUT_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=	gtk20
PKGNAMESUFFIX=	-gtk2
.elif ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.else
CONFIGURE_ARGS+=--disable-gtk
.endif

MAN1=		nessus.1 nessus-fetch.1 nessus-mkrand.1 nessus-mkcert-client.1
MAN8=		nessusd.8 nessus-adduser.8 nessus-mkcert.8 nessus-rmuser.8

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

SED_SCRIPT=	-e 's,%%PKGNAME%%,${PKGNAME},g' \
		-e 's,%%PREFIX%%,${PREFIX},g'

post-build:
.for script in pkg-deinstall
	@${SED} ${SED_SCRIPT} ${SCRIPTDIR}/${script} > ${WRKDIR}/${script}.sh
.endfor

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/nessusd.sh > ${PREFIX}/etc/rc.d/nessusd.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/nessusd.sh
	@${SED} -e 's;\$${PREFIX};${PREFIX};' ${FILESDIR}/nessusd.conf \
		> ${PREFIX}/etc/nessus/nessusd.conf.dist
	@${SED} -e 's;\$${PREFIX};${PREFIX};' ${FILESDIR}/nessusd.rules \
		> ${PREFIX}/etc/nessus/nessusd.rules.dist
	@${CHMOD} 644 ${PREFIX}/etc/nessus/nessusd.conf.dist \
		${PREFIX}/etc/nessus/nessusd.rules.dist
	@if [ ! -f ${PREFIX}/etc/nessus/nessusd.conf ]; then \
		${CP} -p ${PREFIX}/etc/nessus/nessusd.conf.dist \
			${PREFIX}/etc/nessus/nessusd.conf; \
	fi
	@if [ ! -f ${PREFIX}/etc/nessus/nessusd.rules ]; then \
		${CP} -p ${PREFIX}/etc/nessus/nessusd.rules.dist \
			${PREFIX}/etc/nessus/nessusd.rules; \
	fi
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/move_nessus
.if ! exists(${PREFIX}/var/CA/serverkey.pem)
	@${ECHO} ""
	@${ECHO} "**************************************************************************"   
	@${ECHO} "To create and install a new certificate, type \"make cert\""
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
.endif
	@${CAT} ${PKGMESSAGE}

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${PREFIX}/var/CA/serverkey.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	${PREFIX}/sbin/nessus-mkcert

.include <bsd.port.post.mk>
