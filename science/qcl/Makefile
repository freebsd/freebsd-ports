# Created by: Brad Huntting <huntting@glarp.com>
# $FreeBSD$

PORTNAME=	qcl
PORTVERSION=	0.6.3
CATEGORIES=	science math
MASTER_SITES=	http://tph.tuwien.ac.at/~oemer/tgz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quantum computer simulator

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	PLOTUTILS
PLOTUTILS_DESC=	Plotting support via plotutils

USES=		bison gmake readline
USE_GCC=	any

PLIST_FILES=	bin/qcl \
		%%DATADIR%%/default.qcl %%DATADIR%%/deutsch.qcl \
		%%DATADIR%%/dft.qcl %%DATADIR%%/examples.qcl \
		%%DATADIR%%/grover.qcl %%DATADIR%%/linalg.qcl \
		%%DATADIR%%/modarith.qcl %%DATADIR%%/primes.qcl \
		%%DATADIR%%/shor.qcl %%DATADIR%%/test.qcl
PLIST_DIRS=	%%DATADIR%%

PLOTUTILS_LIB_DEPENDS=	libplotter.so:${PORTSDIR}/graphics/plotutils
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
