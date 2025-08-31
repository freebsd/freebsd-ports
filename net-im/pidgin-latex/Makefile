PORTNAME=	latex
PORTVERSION=	1.0
PORTREVISION=	15
CATEGORIES=	net-im
MASTER_SITES=	SF/pidgin-${PORTNAME}/pidgin-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	mainland@apeiron.net
COMMENT=	Display LaTeX output in your IMs
WWW=		https://sourceforge.net/projects/pidgin-latex/

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:net-im/pidgin
RUN_DEPENDS=	pidgin:net-im/pidgin

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

USES=		gmake gnome magick:6,run pkgconfig tar:bzip2 tex
USE_TEX=	latex
USE_GNOME=	gtk20
MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	lib/pidgin/LaTeX.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pidgin
	${INSTALL_LIB} ${WRKSRC}/LaTeX.so ${STAGEDIR}${PREFIX}/lib/pidgin

.include <bsd.port.mk>
