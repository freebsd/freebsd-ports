# ex:ts=8
# New ports collection makefile for:	fxt
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fxt
PORTVERSION=	2001.10.15
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-patch:
	@${PERL} -pi -e "s,^CXX,#CXX,g ; \
		s,^PREFIX,#PREFIX,g" ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
