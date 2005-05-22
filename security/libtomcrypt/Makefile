# Ports collection makefile for:  libtomcrypt
# Date created:			  22 Jan 2004
# Whom:				  Yonatan <Yonatan@Xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libtomcrypt
PORTVERSION=	1.02
CATEGORIES=	security
MASTER_SITES=	http://libtomcrypt.org/files/
DISTNAME=	crypt-${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Comprehensive, modular and portable cryptographic toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	library

OPTIONS=	DOCS "build documentation (depends on teTeX)" off

.include <bsd.port.pre.mk>

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.else
NOPORTDOCS=	yes
INSTALL_TARGET=	install_lib
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|; s|dvipdf|dvipdft|; \
		 s|-O3||; s|-funroll-loops||; s|-fomit-frame-pointer||; \
		 s|-Wno-unused-parameter||' \
		${WRKSRC}/makefile

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC}/demos/test && ${MAKE} test ${MAKE_ARGS} && ${WRKSRC}/demos/test/test)
.endif

.include <bsd.port.post.mk>
