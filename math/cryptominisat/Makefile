# $FreeBSD$

PORTNAME=	cryptominisat
PORTVERSION=	4.2.0
PORTREVISION?=	0
CATEGORIES?=	math
MASTER_SITES=	http://msoos.org/largefiles/

MAINTAINER=	6yearold@gmail.com
COMMENT?=	General-purpose award-winning SAT solver

LICENSE?=	LGPL3

LIB_DEPENDS?=	libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USES?=		cmake compiler:c++11-lib tar:bzip2
CMAKE_ARGS=	-DNOMYSQL=1 -DNOM4RI=1 -DPYTHON_EXECUTABLE=0
WRKSRC=		${WRKDIR}/${PORTNAME}4-${PORTVERSION}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
