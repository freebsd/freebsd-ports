# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	polyorb
PORTVERSION=	2.11.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	polyorb-gpl-${YEAR}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CORBA, SOAP, Ada 95 Distributed System Annex middleware

LICENSE=	GPLv3

BUILD_DEPENDS=	xmlada>=3.2:textproc/xmlada

USES=		ada gmake python:2.7,build shebangfix
GNU_CONFIGURE=	yes
NO_MTREE=	yes
YEAR=		2014
WRKSRC=		${WRKDIR}/polyorb-${YEAR}-src

ALL_TARGET=	default
MAKE_ENV=	PROCESSORS=${MAKE_JOBS_NUMBER}
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD} \
		ac_cv_prog_CXXCPP="cpp -E" \
		ac_cv_prog_SVN=false
PORTDOCS=	html \
		info/polyorb_ug.info \
		pdf/polyorb_ug.pdf \
		txt/polyorb_ug.txt
SHEBANG_FILES=	compilers/idlac/*.py testsuite/*.py testsuite/tests/*.py

CONFIGURE_ARGS=	--with-appli-perso="corba dsa moma" \
		--with-proto-perso="giop soap srp" \
		--with-corba-services="event ir naming notification time"

# Polyorb 2011 = PCS version 4   GNAT GCC 4.6 = PCS version 4
# Polyorb 2012 = PCS version 5   GNAT GCC 4.7 = PCS version 5
# Polyorb 2013 = PCS version 6   GNAT GCC 4.9 = PCS version 6
# Polyorb 2014 = PCS version 6   GNAT GCC 4.9 = PCS version 6

OPTIONS_DEFINE=	DOCS TESTSUITE
OPTIONS_SUB=	yes

TESTSUITE_ALL_TARGET=	testsuite
TESTSUITE_BUILD_DEPENDS=gnatpython>=20101207:devel/gnatpython
TESTSUITE_DESC=		Enable 'make run-testsuite' target


.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	${MV} ${WRKSRC}/docs/polyorb_ug.html ${WRKSRC}/docs/ug.html
.endif
	@${REINPLACE_CMD} -e 's|bash|/bin/sh|' ${WRKSRC}/testsuite/testsuite.py

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	(cd ${STAGEDIR}${PREFIX}; \
		${FIND} * -type d -empty -print | ${XARGS} ${RMDIR})

.if ${PORT_OPTIONS:MTESTSUITE}
# must be run after "make install"
run-testsuite:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} run_tests)
.endif

.include <bsd.port.mk>
