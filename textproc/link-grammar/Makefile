# New ports collection makefile for:	link-grammar
# Date created:				22 May 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	link-grammar
PORTVERSION=	4.5.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A grammar checking library

USE_GNOME=	gnomehack gnometarget ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
USE_CSTD=	gnu99
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--enable-pthreads \
		--disable-java-bindings

DOCS=		AUTHORS LICENSE MAINTAINERS README
MAN1=		link-parser.1

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure ${WRKSRC}/${PORTNAME}/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
