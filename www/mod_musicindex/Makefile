# New ports collection makefile for:	mod_musicindex
# Date created:				Nov 1 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	mod_musicindex
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	www audio
MASTER_SITES=	http://www.esiee.fr/~puffin/musicindex/
DISTNAME=	libapache-mod-musicindex_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module in C implements Perl module Apache::MP3

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad

APXS?=		${LOCALBASE}/sbin/apxs
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/libapache-mod-musicindex-${PORTVERSION}
MAKE_ENV+=	APXS=${APXS} BUILDDIR=${WRKSRC}

PORTDOCS=	directory.png musicindex.css fetch.png \
			right_arrow.gif general.png sound.png

.if defined (WITH_APACHE2)
MODULE_EXT=	la
MAKEFILE=	Makefile.apache2
PLIST_SUB+=	MOD_DIR=libexec/apache2
APACHE_PORT?=	www/apache2
MAKE_TARGET=	all
.else
MODULE_EXT=	so
PLIST_SUB+=	MOD_DIR=libexec/apache
APACHE_PORT?=	www/apache13
.endif

post-patch:
	@${CP} ${WRKSRC}/modules.mk.apache2 ${WRKSRC}/modules.mk
	@${TOUCH} ${WRKSRC}/.deps

do-install:
	${APXS} -i -n musicindex -A ${WRKSRC}/mod_musicindex.${MODULE_EXT}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/musicindex/${f} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
