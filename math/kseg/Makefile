# New ports collection makefile for:	kseg
# Date created:		4 September 2001
# Whom:			Kuang-che Wu <kcwu@ck.tp.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	kseg
PORTVERSION=	0.3
CATEGORIES=	math graphics
MASTER_SITES=	http://www.mit.edu/~ibaran/

MAINTAINER=	kcwu@ck.tp.edu.tw

USE_GCC=	2.95
USE_QT_VER=	2
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

pre-configure:
	${REINPLACE_CMD} -e "s@\\$$(QTDIR)/include@${PREFIX}/include/qt2@" ${WRKSRC}/Makefile ${WRKSRC}/formula/Makefile
	${REINPLACE_CMD} -e "s@\\$$(QTDIR)/lib -lqt@${PREFIX}/lib -lqt2@" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s@^MOC =.*@MOC = ${MOC}@" ${WRKSRC}/Makefile ${WRKSRC}/formula/Makefile
	${REINPLACE_CMD} -e 's@"LanguageDir", "\."@"LanguageDir", "${PREFIX}/share/doc/kseg"@' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kseg ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/kseg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/kseg
.for TRANS in de en fr pt xx
	${INSTALL_DATA} ${WRKSRC}/kseg_${TRANS}.qm ${PREFIX}/share/doc/kseg
.endfor
	${MKDIR} ${PREFIX}/share/doc/kseg/examples
	for EXAMPLES in ${WRKSRC}/examples/*;do ${INSTALL_DATA} $${EXAMPLES} ${PREFIX}/share/doc/kseg/examples;done

.include <bsd.port.mk>
