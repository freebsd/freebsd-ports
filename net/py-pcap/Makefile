# New ports collection makefile for:	py-pcap
# Date created:		24 Nov 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylibpcap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibpcap-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${SWIG_CMD}:${PORTSDIR}/devel/SWIG

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}
SWIG_CMD?=	${LOCALBASE}/bin/swig
WRKSRC=		${WRKDIR}/pylibpcap
USE_PYTHON=	yes

post-patch:
	${SED} -e 's|^\(PYTHON_INCLUDES=\).*|\1-I${PYTHON_INCLUDEDIR}|g' \
		-e 's|^\(SWIG=\).*|\1${SWIG_CMD}|g' \
		${WRKSRC}/Makefile > ${WRKSRC}/Makefile.temp && \
		${MV} -f ${WRKSRC}/Makefile.temp ${WRKSRC}/Makefile
	${SED} -e 's|pcap/pcap\.h|pcap.h|g' \
		${WRKSRC}/pypcap.h > ${WRKSRC}/pypcap.h.temp && \
		${MV} -f ${WRKSRC}/pypcap.h.temp ${WRKSRC}/pypcap.h

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
.for f in pcapcmodule.so pcap.py pcap.pyc pcap.pyo
	${INSTALL_DATA} ${WRKSRC}/$f ${PYTHON_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sniff.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
