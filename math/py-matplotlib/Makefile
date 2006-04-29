# ex:ts=8
# Ports collection makefile for:	py-matplotlib
# Date created:			Aug 4, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	matplotlib
PORTVERSION=	0.87.2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	A plotting library uses a syntax familiar to matlab users

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${LOCALBASE}/lib/libagg.a:${PORTSDIR}/graphics/agg
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
.endif

CONFLICTS=	devel/py-dateutil-[0-9]*

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes
USE_GNOME=	gtk20 pygtk2
CFLAGS+=	-I${X11BASE}/include

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PLISTDIR=	${PYTHON_SITELIBDIR}/${PORTNAME} ${PYTHON_SITELIBDIR}/dateutil ${PYTHON_SITELIBDIR}/pytz \
		${PYTHON_SITELIBDIR}/pylab*
.if !defined(NOPORTDOCS)
PLISTDIR+=	${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500000)
USE_GCC=	3.4
.endif

post-patch:
	@${GREP} -lR "share/matplotlib" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s,share/matplotlib,share/py-matplotlib,g"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif
.for dir in ${PLISTDIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
