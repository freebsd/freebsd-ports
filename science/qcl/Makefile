# Created by: Brad Huntting <huntting@glarp.com>
# $FreeBSD$

PORTNAME=	qcl
PORTVERSION=	0.6.4
CATEGORIES=	science math
MASTER_SITES=	http://tph.tuwien.ac.at/~oemer/tgz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quantum computer simulator

LICENSE=	GPLv2+

USES=		bison gmake readline tar:tgz

PLIST_FILES=	bin/qcl
PORTDATA=	*

OPTIONS_DEFINE=		PLOTUTILS

PLOTUTILS_DESC=		Plotting support via plotutils
PLOTUTILS_LIB_DEPENDS=	libplotter.so:graphics/plotutils
PLOTUTILS_CXXFLAGS=	-I${LOCALBASE}/include -DQCL_PLOT
PLOTUTILS_LDFLAGS=	-L${LOCALBASE}/lib -lplotter

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}| ; \
		 s|lib/qcl|share/qcl| ; \
		 s|-O2 -g|| ; \
		 s|^PLOPT|#PLOPT| ; \
		 s|^PLLIB|#PLLIB| ; \
		 /^CXXFLAGS/s| =| +=| ; \
		 /^LDFLAGS/s| =| +=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|-g -O2|| ; \
		 /^CXXFLAGS/s| =| +=| ; \
		 /^LDFLAGS/s| =| +=|' ${WRKSRC}/qc/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} qcl ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} *.qcl ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
