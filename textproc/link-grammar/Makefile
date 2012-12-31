# $FreeBSD$

PORTNAME=	link-grammar
PORTVERSION=	4.7.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A grammar checking library

LIB_DEPENDS=	pspell.16:${PORTSDIR}/textproc/aspell

USE_GNOME=	gnomehack ltverhack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
USE_CSTD=	gnu99
CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-pthreads \
		--disable-java-bindings \
		--disable-hunspell \
		--enable-aspell
MAKE_JOBS_UNSAFE=	yes

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
