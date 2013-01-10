# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bro
PORTVERSION=	2.1
CATEGORIES=	security
MASTER_SITES=	http://www.bro-ids.org/downloads/release/

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	System for detecting network intruders in real-time

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

USE_PERL5=	yes
USE_CMAKE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

OPTIONS_DEFINE=	IPV6 LBL_HF LBL_CF ASSERT BROCCOLI
OPTIONS_DEFAULT=IPV6 LBL_HF LBL_CF
LBL_HF_DESC=	Address to hostname filter support
LBL_CF_DESC=	Unix time to formated time/date filter support
BROCCOLI_DESC=	Build support for libbroccoli communications
OPTIONS_EXCLUDE=NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBROCCOLI}
CMAKE_ARGS+=	-DINSTALL_BROCCOLI:BOOL=ON \
		-DDISABLE_PYTHON_BINDINGS:BOOL=ON \
		-DDISABLE_RUBY_BINDINGS:BOOL=ON
PLIST_SUB+=	BROCCOLI=""
.else
PLIST_SUB+=	BROCCOLI="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CMAKE_ARGS+=	-DBROv6:BOOL=ON
.endif

.if ${PORT_OPTIONS:MLBL_HF}
RUN_DEPENDS+=	hf:${PORTSDIR}/sysutils/lbl-hf
.endif

.if ${PORT_OPTIONS:MLBL_CF}
RUN_DEPENDS+=	cf:${PORTSDIR}/sysutils/lbl-cf
.endif

.if ${PORT_OPTIONS:MASSERT}
CMAKE_ARGS+=	-DENABLE_DEBUG:BOOL=ON
.endif

post-patch:
#	avoid installing .in header file
	${REINPLACE_CMD} -e '13d' ${WRKSRC}/aux/binpac/lib/CMakeLists.txt

.include <bsd.port.mk>
