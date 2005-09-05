# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.4.1
PORTEPOCH=		1
CATEGORIES=		polish net
MASTER_SITES=		http://www.kadu.net/download/stable/
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		mwisnicki+freebsd@gmail.com
COMMENT=		QT Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/ekg\
			sndfile.1:${PORTSDIR}/audio/libsndfile

USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu \
			--with-includes="${LOCALBASE}/include" \
			--with-libs="${LOCALBASE}/lib" \
			--program-transform-name=''\
			--mandir=${PREFIX}/man
CONFIGURE_ENV=		QTDIR="${QT_PREFIX}"

USE_QT_VER=		3
QT_NONSTANDARD=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${X11BASE}/share/gnome/apps/Internet
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${X11BASE}/share/gnome/apps/Internet
	${MKDIR} ${LOCALBASE}/share/applnk/Internet
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${LOCALBASE}/share/applnk/Internet

.include <bsd.port.post.mk>
