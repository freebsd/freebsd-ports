# New ports collection makefile for:	mod_musicindex
# Date created:				Nov 1 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	mod_musicindex
PORTVERSION=	0.8.9
CATEGORIES=	www audio
MASTER_SITES=	http://www.esiee.fr/~puffin/musicindex/
DISTNAME=	libapache-mod-musicindex_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module in C implements Perl module Apache::MP3

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}
LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		id3tag.1:${PORTSDIR}/audio/mad \
		mad.1:${PORTSDIR}/audio/mad

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/libapache-mod-musicindex-${PORTVERSION}

DOCS_HTMLIMAGES=	directory.png musicindex.css fetch.png \
			right_arrow.gif general.png sound.png

do-install:
	${APXS} -i -A -n musicindex ${WRKSRC}/mod_musicindex.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS_HTMLIMAGES}
	${INSTALL_DATA} ${WRKSRC}/musicindex/${f} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
