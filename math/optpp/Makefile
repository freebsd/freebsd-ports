# $FreeBSD$

PORTNAME=	optpp
DISTVERSION=	2.4
CATEGORIES=	math
MASTER_SITES=	https://software.sandia.gov/opt++/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Object-oriented nonlinear optimization library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/GNU_LGPL

USES=		fortran gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

post-stage: # installs the conflicting file
	@${RM} ${STAGEDIR}${PREFIX}/include/cblas.h

.include <bsd.port.mk>
