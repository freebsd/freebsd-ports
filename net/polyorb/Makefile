# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	polyorb
PORTVERSION=	2.11.1
CATEGORIES=	net
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	polyorb-gpl-${YEAR}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	CORBA, SOAP, Ada 95 Distributed System Annex middleware

LICENSE=	GPLv3

BUILD_DEPENDS=	xmlada>=3.2:${PORTSDIR}/textproc/xmlada

USES=		ada gmake python:build
GNU_CONFIGURE=	yes
NO_MTREE=	yes
YEAR=		2014
WRKSRC=		${WRKDIR}/polyorb-${YEAR}-src

MAKE_ENV=	PROCESSORS=${MAKE_JOBS_NUMBER}
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD} \
		ac_cv_prog_CXXCPP="cpp -E" \
		ac_cv_prog_SVN=false

CONFIGURE_ARGS=	--with-appli-perso="corba dsa moma" \
		--with-proto-perso="giop soap srp" \
		--with-corba-services="event ir naming notification time"

# Polyorb 2011 = PCS version 4   GNAT GCC 4.6 = PCS version 4
# Polyorb 2012 = PCS version 5   GNAT GCC 4.7 = PCS version 5
# Polyorb 2013 = PCS version 6   GNAT GCC 4.9 = PCS version 6
# Polyorb 2014 = PCS version 6   GNAT GCC 4.9 = PCS version 6

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} default

post-install:
	@(cd ${STAGEDIR}${PREFIX}; \
		${FIND} * -type d -empty -print | ${XARGS} ${RMDIR})
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
