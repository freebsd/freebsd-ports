# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.3.9
PORTREVISION=		1
PORTEPOCH=		1
CATEGORIES=		polish net
MASTER_SITES=		http://www.kadu.net/download/stable/
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		jacek@combit.com.pl
COMMENT=		QT Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/ekg\
			gsm.1:${PORTSDIR}/audio/gsm

USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu \
			--program-transform-name=''\
			--mandir=${PREFIX}/man
CONFIGURE_ENV=		LDFLAGS="-L${LOCALBASE}/lib"\
			GADU_INCLUDES="-I${LOCALBASE}/include"\
			GSM_LIB="-L${LOCALBASE}/lib"\
			GSM_INCLUDES="-I${LOCALBASE}/include"

USE_QT_VER=		3

WRKSRC=			${WRKDIR}/${PORTNAME}

WANT_GNOME=		yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "  **************************************************************"
	@${ECHO_MSG} "  * This version of kadu requires polish/ekg-1.4.20040208,1 or *"
	@${ECHO_MSG} "  * higher, so upgrade it first if necessary.                  *"
	@${ECHO_MSG} "  **************************************************************"
	@${ECHO_MSG}

post-install:
.if ${HAVE_GNOME:Mgnomehier}!=""
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${X11BASE}/share/gnome/apps/Internet
.endif
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${LOCALBASE}/share/applnk/Internet

.include <bsd.port.post.mk>
