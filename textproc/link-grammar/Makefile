# $FreeBSD$

PORTNAME=	link-grammar
PORTVERSION=	4.7.4
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grammar checking library

LIB_DEPENDS=	libaspell.so:textproc/aspell

OPTIONS_DEFINE=	DOCS

USES=		dos2unix gmake libtool pathfix
USE_LDCONFIG=	yes
USE_CSTD=	gnu99
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pthreads \
		--disable-java-bindings \
		--disable-hunspell \
		--enable-aspell
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS LICENSE MAINTAINERS README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
