# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flowcanvas
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive Gtkmm/Gnomecanvasmm widget

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libgvc.so:${PORTSDIR}/graphics/graphviz \
		libgnomecanvasmm-2.6.so:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24

USES=		pkgconfig
USE_BZIP2=	yes
USE_PYTHON_BUILD=yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
WAF_VERBOSE=	--verbose
.endif

WAF_JOBS=	--jobs=${MAKE_JOBS_NUMBER}

post-patch:
	@${REINPLACE_CMD} -e \
		"s|$$[{]LIBDIRNAME[}]/pkgconfig|libdata/pkgconfig| ; \
		 s|-fshow-column'|-fshow-column ${CXXFLAGS}'|" \
			${WRKSRC}/autowaf/autowaf.py

do-configure:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} --prefix=${PREFIX} configure)

do-build:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} ${WAF_JOBS} build)

do-install:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} install)

.include <bsd.port.post.mk>
