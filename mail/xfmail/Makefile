# New ports collection makefile for:	xfmail
# Date created:		30 June 1996
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xfmail
PORTVERSION=	1.5.5
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	ftp://xfmail.cfreeze.com/pub/xfmail/release/%SUBDIR%/	\
		ftp://ftp.welcomes-you.com/pub/xfmail/release/%SUBDIR%/	\
		ftp://xfmail.ufies.org/pub/xfmail/release/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X Window System application for receiving electronic mail

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	xpm
USE_LDCONFIG=	yes

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
	@echo

post-patch:
	@${REINPLACE_CMD} -e 's/libeditor/libxfeditor/g' \
		${WRKSRC}/src/editor/Makefile.* \
		${WRKSRC}/src/ui/Makefile.*

.include <bsd.port.post.mk>
