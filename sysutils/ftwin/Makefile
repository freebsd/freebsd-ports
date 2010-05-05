# New ports collection makefile for:	ftwin
# Date created:		2007-12-05
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ftwin
PORTVERSION=	0.8.5
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://download.meroware.org/ftwin/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	A useful tool to find duplicate files

LIB_DEPENDS=	puzzle.1:${PORTSDIR}/graphics/libpuzzle \
		apr-1:${PORTSDIR}/devel/apr \
		pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262 aclocal:110 automake:110 autoheader:262
CONFIGURE_ARGS+=	--with-puzzle=${LOCALBASE}
PLIST_FILES=	bin/ftwin

MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS EXAMPLES TODO CHANGES KNOWN_BUGS VERSION LICENSE README

MAN8=		ftwin.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
