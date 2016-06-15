# Created by: ijliao
# $FreeBSD$

PORTNAME=	fxt
PORTVERSION=	2016.06.02
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFT code and related stuff

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake tar:tgz
MAKE_ENV=	FXT_INSTALL="${INSTALL_DATA}"
MAKEFILE=	makefile

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(FXT_CXXFLAGS\)|#\1| ; \
		 s|\([[:space:]]\)\($$(INCDIR)\)|\1$$(DESTDIR)\2|g ; \
		 s|\([[:space:]]\)\($$(LIBDIR)\)|\1$$(DESTDIR)\2|g' \
		${WRKSRC}/makefile

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
