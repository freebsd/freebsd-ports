# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	pft
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.phenoelit.org/hp/
DISTNAME=	libPJL-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Printer Job Language library and tool

NO_WRKSUBDIR=	yes

USES=		gmake tar:tgz
ALL_TARGET=	libPJL.a

PLIST_FILES=	bin/pft lib/libPJL.a

post-patch:
.for i in Makefile pft/Makefile
	@${REINPLACE_CMD} -e \
		'/^CPP/s|=g++|=$${CXX} $${CXXFLAGS}| ; \
		 /^CPPFLAGS=/s| -g | |' ${WRKSRC}/${i}
.endfor

post-build:
	@(cd ${WRKSRC}/pft; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} pft)

do-install:
	(cd ${WRKSRC}/pft && ${INSTALL_PROGRAM} pft \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} libPJL.a \
		${STAGEDIR}${PREFIX}/lib)

.include <bsd.port.mk>
