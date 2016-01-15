# Created by: ijliao
# $FreeBSD$

PORTNAME=	fxt
PORTVERSION=	2015.07.17
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFT code and related stuff

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake tar:tgz
MAKEFILE=	makefile

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,^(FXT_CXXFLAGS),#\1,' \
		-e 's,^(CXXFLAGS),#\1,' \
		 ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|sinl|Sin|g' ${WRKSRC}/src/aux0/trigrec.h
	@${REINPLACE_CMD} -e 's|sinl|sin|g' ${WRKSRC}/src/fht/hartleyshift.h

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
