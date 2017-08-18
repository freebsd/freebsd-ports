# Created by: ijliao
# $FreeBSD$

PORTNAME=	fxt
DISTVERSION=	2017.07.25
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/

MAINTAINER=	amutu@amutu.com
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
