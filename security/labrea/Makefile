# New ports collection makefile for:   LaBrea
# Date created:        20 September 2001
# Whom:                nick@rogness.net
#
# $FreeBSD$
##

PORTNAME=	LaBrea
PORTVERSION=	2.4
CATEGORIES=	security
MASTER_SITES=	http://freebsd.rogness.net/ports/labrea/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nick@rogness.net
COMMENT=	Security tarpit defense tool

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LaBrea ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LaBrea.README ${DOCSDIR}
	@echo "******************************************"
	@echo "You will need to read the LaBrea.README in"
	@echo "${DOCSDIR}"
	@echo "Before your run this!!"
	@echo "******************************************"
	@echo .
.endif

.include <bsd.port.mk>
