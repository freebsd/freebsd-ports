# New ports collection makefile for:	diffsplit
# Date created:				2002-10-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	diffsplit
PORTVERSION=	1.0
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.pathname.com/~quinlan/software/diffsplit/
DISTNAME=	diffsplit
EXTRACT_SUFX=

MAINTAINER=	trevor@FreeBSD.org

NO_WRKSRC=	YES
PLIST=		${WRKDIR}/pkg-plist
USE_PERL5=	YES

pre-install:
	${ECHO_CMD} bin/diffsplit > ${PLIST}

.include <bsd.port.mk>
