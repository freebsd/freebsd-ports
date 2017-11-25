# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	pft
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.phenoelit.org/hp/
DISTNAME=	libPJL-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Printer Job Language library and tool

LICENSE=	NONE

NO_WRKSUBDIR=	yes

USES=		gmake tar:tgz

PLIST_FILES=	bin/pft lib/libPJL.a

post-patch:
.for i in Makefile pft/Makefile
	@${REINPLACE_CMD} -e \
		'/^CPP/s|=g++|=$${CXX} $${CXXFLAGS}| ; \
		 /^CPPFLAGS=/s| -g | |' ${WRKSRC}/${i}
.endfor

do-build:
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} libPJL.a)
	@(cd ${WRKSRC}/pft && ${DO_MAKE_BUILD} pft)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pft/pft ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libPJL.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
