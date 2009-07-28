# New ports collection makefile for:	mxml
# Date created:		2007-10-12
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mxml
PORTVERSION=	2.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	mxml/${PORTVERSION}

MAINTAINER=	hsmtkk@gmail.com
COMMENT=	Small XML parsing library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--with-docdir=no
MAKE_JOBS_SAFE=	yes

MAN1=	mxmldoc.1
MAN3=	mxml.3

PORTDOCS=	*

PLIST_FILES=	bin/mxmldoc include/mxml.h \
		lib/libmxml.a \
		libdata/pkgconfig/mxml.pc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${PORTDOCS:S,^,${WRKSRC}/doc,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
