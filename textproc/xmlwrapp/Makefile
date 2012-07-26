# ex:ts=8
# Ports collection makefile for:	xmlwrapp
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlwrapp
PORTVERSION=	0.6.3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern style C++ library for working with XML data

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	boost_iostreams.4:${PORTSDIR}/devel/boost-libs

OPTIONS=	XSLT "build libxsltwrap library (requires libxslt)" off

USE_GNOME=	gnomehack libxml2
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if defined(WITH_XSLT)
USE_GNOME+=	libxslt
PLIST_SUB+=	XSLT=""
.else
CONFIGURE_ARGS+=--disable-xslt
PLIST_SUB+=	XSLT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.include <bsd.port.mk>
