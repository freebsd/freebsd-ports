# New ports collection makefile for:	mod_musicindex
# Date created:				Nov 1 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	mod_musicindex
PORTVERSION=	0.99.7
PORTREVISION=	2
CATEGORIES=	www audio
# Master site doesn't have a current version'd tarball...
#MASTER_SITES=	http://www.parisc-linux.org/~varenet/musicindex/
MASTER_SITES=	http://depot.fsck.ch/mirror/distfiles/
DISTNAME=	libapache-mod-musicindex_${PORTVERSION}

MAINTAINER=	ports@fsck.ch
COMMENT=	Apache module in C that implements the perl module Apache::MP3

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		FLAC.7:${PORTSDIR}/audio/flac

CPPFLAGS=	-DHAS_MP3 -DHAS_OGG -DHAS_FLAC
CFLAGS+=	-I${LOCALBASE}/include

#WANT_APACHE=	YES
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/libapache-mod-musicindex-${PORTVERSION}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

MAKE_ENV+=	APXS=${APXS} CPPFLAGS="${CPPFLAGS}" LDFLAGS="-L${LOCALBASE}/lib"

.if "${AP_VER}"=="2"
MAKE_ENV+=	APACHE_VERSION=2 APRCONFIG=${LOCALBASE}/lib/apache2/apr-config
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
