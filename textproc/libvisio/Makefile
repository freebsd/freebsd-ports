# $FreeBSD$

PORTNAME=	libvisio
PORTVERSION=	0.0.31
CATEGORIES=	textproc devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing the visio file format structure

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/include/classic_core.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg

CONFIGURE_ARGS=	--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XZ=		yes
USES=		gmake pathfix perl5 pkgconfig

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 802516 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900502)
BUILD_DEPENDS+=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf
CONFIGURE_ENV+=	GPERF=${LOCALBASE}/bin/gperf
.endif

.include <bsd.port.post.mk>
