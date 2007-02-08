# New ports collection makefile for:   ctpp
# Date created:         19 July 2004
# Whom:                 shetuhin@corp.mail.ru (Andrei V. Shetuhin)
#
# $FreeBSD$
#

PORTNAME=	ctpp
PORTVERSION=	1.8.4
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.reki.ru/products/ctpp/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to use templates in C/C++ projects

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_LDCONFIG=	yes

do-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/cmake ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libctpp-st.a ${PREFIX}/lib/libctpp.a
	${INSTALL_DATA} ${WRKSRC}/libctpp.so.${PORTVERSION} ${PREFIX}/lib/libctpp.so
	@${MKDIR} ${PREFIX}/include/ctpp
	cd ${WRKSRC}/include && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/ctpp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
