# New ports collection makefile for:	xfmail
# Date created:		30 June 1996
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xfmail
PORTVERSION=	1.5.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://xfmail.cfreeze.com/pub/xfmail/release/%SUBDIR%/	\
		ftp://ftp.welcomes-you.com/pub/xfmail/release/%SUBDIR%/	\
		ftp://xfmail.ufies.org/pub/xfmail/release/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/source/

MAINTAINER=	mikeh@FreeBSD.org
COMMENT=	An X Window System application for receiving electronic mail

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		gdbm.3:${PORTSDIR}/databases/gdbm

CONFLICTS=	qt-3.*

USE_BZIP2=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--with-dbm-lib=gdbm

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-esd-sound
.endif

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=	--with-nas-sound
.endif

.if defined(WITH_FACES)
LIB_DEPENDS+=	compface:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--with-faces
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap12
CONFIGURE_ARGS+=	--with-ldap
.endif

MAN1=		xfmail.1

pre-everything::
	@echo
.ifndef(WITH_ESOUND)
	@echo "To build with esound support, restart make and define WITH_ESOUND"
.endif
.ifndef(WITH_NAS)
	@echo "To build with Network Audio System support, restart make and define WITH_NAS"
.endif
.ifndef(WITH_FACES)
	@echo "To build with faces support, restart make and define WITH_FACES"
.endif
.ifndef(WITH_LDAP)
	@echo "To build with LDAP support, restart make and define WITH_LDAP"
.endif
	@echo

.include <bsd.port.post.mk>
