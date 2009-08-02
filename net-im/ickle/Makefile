# ex:ts=8
# New ports collection makefile for:	ickle
# Date created:			Nov 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ickle
PORTVERSION=	0.3.2
PORTREVISION=	6
CATEGORIES=	net-im devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICQ2000 protocol implementation

LIB_DEPENDS=	gtkmm-1.2.2:${PORTSDIR}/x11-toolkits/gtkmm12 \
		icq2000.5:${PORTSDIR}/net-im/libicq2000

USE_GNOME=	gtk12
WANT_GNOME=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-sigc-prefix=${LOCALBASE} \
		--with-gtkmm-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="`${LOCALBASE}/bin/sigc-config --cflags`"

post-patch:
	@${REINPLACE_CMD} -E -e 's|(gtkmm_config_args[[:space:]]*=).+$$|\1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!="" || defined(WITH_GNOME)
USE_GNOME+=	libcapplet
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	GNOME="" NOGNOME="@comment "
.else
CONFIGURE_ARGS+=	--with-gnome=no

PLIST_SUB+=	GNOME="@comment " NOGNOME=""
.endif

.if defined(WITH_ICKLE_CONTROL)
PLIST_SUB+=	ICKLECONTROL=""
.else
CONFIGURE_ARGS+=	--without-ickle-control

PLIST_SUB+=	ICKLECONTROL="@comment "
.endif

pre-everything::
.if ${HAVE_GNOME:Mlibcapplet}=="" && !defined(WITH_GNOME)
	@${ECHO_MSG} "===> Define WITH_GNOME		to enable GNOME support"
.endif
.if !defined(WITH_ICKLE_CONTROL)
	@${ECHO_MSG} "===> Define WITH_ICKLE_CONTROL	to enable external command-line"
	@${ECHO_MSG} "===>				control for the ickle client"
.endif

.include <bsd.port.post.mk>
