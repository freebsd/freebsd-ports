# New ports collection makefile for: 	nessus-devel
#
# $FreeBSD$
#
# If you want to only have the command-line client even if gtk is already
# installed define one of these:
#  WITHOUT_GNOME
#  WITHOUT_GTK
#  WITHOUT_NESSUS_GTK

PORTNAME=	nessus-devel
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		http://ftp.gwdg.de/pub/linux/misc/nessus/nessus-${PORTVERSION}/src/ \
		ftp://sunsite.cnlab-switch.ch/mirror/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.au.nessus.org/pub/nessus/nessus-${PORTVERSION}/src/ \
		ftp://ftp.ayamura.org/pub/nessus/nessus-${PORTVERSION}/src/
DISTNAME=	nessus-core-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	A security scanner: looks for vulnerabilities in a given network

CONFLICTS=	nessus-[0-9]* nessus-gtk-[0-9]* nessus-gtk2-[0-9]*
LIB_DEPENDS=	nasl.3:${PORTSDIR}/security/nessus-libnasl-devel

DIST_SUBDIR=	nessus
WRKSRC=		${WRKDIR}/nessus-core

USE_LIBTOOL_VER=13
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

MAN1=		nessus.1 nessus-mkrand.1 nessus-mkcert-client.1
MAN8=		nessusd.8 nessus-adduser.8 nessus-mkcert.8 nessus-rmuser.8

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-install:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/nessusd.sh > ${LOCALBASE}/etc/rc.d/nessusd.sh
	@${CHMOD} +x ${LOCALBASE}/etc/rc.d/nessusd.sh
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/move_nessus
.if ! exists(${PREFIX}/var/CA/serverkey.pem)
.if ! defined(BATCH)
	${PREFIX}/sbin/nessus-mkcert
.else
	${PREFIX}/sbin/nessus-mkcert -q
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
