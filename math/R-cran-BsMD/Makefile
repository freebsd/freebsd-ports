# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	BsMD
DISTVERSION=	2020.4.30
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Bayes Screening and Model Discrimination

LICENSE=	GPLv2+

USES=	cran:auto-plist cran:compiles

#Bogus stage-qa as this is $ARCH dependent
NO_ARCH_IGNORE=	BsMD.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/BsMD/libs/BsMD.so

.include <bsd.port.mk>
