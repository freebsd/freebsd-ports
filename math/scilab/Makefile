# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	js@jeannot.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	xless:${PORTSDIR}/misc/xless \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83 \
		pvm:${PORTSDIR}/net/pvm

PVM_ROOT=	${PREFIX}/lib/pvm

NO_CDROM=	"Don't sell for profit."

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--without-xless --with-tk \
		--with-tk-library=${PREFIX}/lib --with-tk-include=${PREFIX}/include/tk8.3 \
		--with-tcl-library=${PREFIX}/lib --with-tcl-include=${PREFIX}/include/tcl8.3 \
		--with-xaw3d

CONFIGURE_ENV=	PVM_ROOT=${PVM_ROOT} PVM_LIB=${PREFIX}/lib
MAKE_ENV=	PVM_INCLUDE=${PREFIX}/include

post-extract:
	${RM} ${WRKSRC}/examples/callsci/callsciJava/config/config
	${RM} ${WRKSRC}/examples/callsci/callsciFortran/config/config
	${RM} ${WRKSRC}/examples/callsci/callsciC/config/config
	${RM} ${WRKSRC}/examples/callsci/callsciC++/config/config

pre-patch:
	@${PERL} -pi -e 's|\r\n|\n|' ${WRKSRC}/macros/util/formatman.sci

post-patch:
	@${PERL} -pi -e 's,%%PVM_ROOT%%,${PVM_ROOT},' \
		${WRKSRC}/scripts/scilab.g

pre-install:
	find ${WRKSRC} -name \*.orig -delete

.include <bsd.port.mk>
