# ex:ts=8
# Ports collection makefile for:	it++
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	it++
PORTVERSION=	3.8.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	itpp
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematical, signal processing and communication library

LIB_DEPENDS=	atlas.1:${PORTSDIR}/math/atlas

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	opt
USE_GMAKE=	yes
USE_GCC=	3.3+

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|sparc|__sparc__|" \
		-e "s|alpha|__alpha__|" ${WRKSRC}/include/base/machdep.h
	@${REINPLACE_CMD} -e "s|[$$]{it_dir}|${LOCALBASE}|g" ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/it-config ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libit++.a ${PREFIX}/lib
	${CP} -R ${WRKSRC}/include ${PREFIX}/include/it++
	${FIND} ${PREFIX}/include/it++ -name \*.orig -delete

.include <bsd.port.post.mk>
