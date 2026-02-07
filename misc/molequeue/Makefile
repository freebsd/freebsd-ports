PORTNAME=	molequeue
DISTVERSION=	0.9.0-17
DISTVERSIONSUFFIX=	-g0a35627
CATEGORIES=	misc
#MASTER_SITES=	https://github.com/OpenChemistry/molequeue/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Desktop integration of high performance computing resources
WWW=		https://www.openchemistry.org/projects/molequeue

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		core gui network widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
