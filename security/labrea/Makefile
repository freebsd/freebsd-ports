# New ports collection makefile for:   LaBrea
# Date created:        20 September 2001
# Whom:                nick@rogness.net
#
# $FreeBSD$
##

PORTNAME=	LaBrea
PORTVERSION=	2.3
CATEGORIES=	security
MASTER_SITES=	http://www.hackbusters.net/LaBrea/
DISTNAME=	LaBrea${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nick@rogness.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/LaBrea
USE_REINPLACE=	yes

MAKE_ARGS=	CC="${CC}" OPTFLAGS="${CFLAGS}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/LaBrea
	${INSTALL_MAN} ${WRKSRC}/LaBrea.README ${PREFIX}/share/doc/LaBrea
	@echo "******************************************"
	@echo "You will need to read the LaBrea.README in"
	@echo "${PREFIX}/share/doc/LaBrea"
	@echo "Before your run this!!"
	@echo "******************************************"
	@echo .
.endif

.include <bsd.port.mk>
