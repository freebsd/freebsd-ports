# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.13
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.xcdroast.org/download/
MASTER_SITE_SUBDIR=	xcdroast
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}

MAINTAINER=	lehmann@ans-netz.de

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

CONFIGURE_ARGS=	--with-cdrtools-prefix=${LOCALBASE}

MAN1=		xcdroast.1

.if defined(WITH_NONROOT)
CONFIGURE_ARGS+=--enable-nonrootmode
.else
CONFIGURE_ARGS+=--disable-nonrootmode
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_NONROOT=yes"
	@${ECHO} "         Use xcdroast w/o being root."
	@${ECHO} "         Actually, that breaks all interactions with cdda2wav"
	@${ECHO} "         (For example, you are not able to grab tracks, neither"
	@${ECHO} "         as root, nor as a normal user). Think about WITH_NONROOT"
	@${ECHO} "          - if you are really in need of it (with the attendant"
	@${ECHO} "         circumstanceces noticed above) or not."
	@${ECHO} ""

post-install:
.if defined(WITH_NONROOT)
	@${CAT} ${PKGMESSAGE}
.endif
.include <bsd.port.mk>
