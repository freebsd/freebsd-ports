# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	fftw3
PORTVERSION=	0.3
CATEGORIES=	math rubygems
MASTER_SITES=	RG

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Ruby interface to the FFTW ver.3

RUN_DEPENDS=	rubygem-narray>0:${PORTSDIR}/math/rubygem-narray
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
