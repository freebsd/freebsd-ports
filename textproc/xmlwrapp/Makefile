# ex:ts=8
# Ports collection makefile for:	xmlwrapp
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlwrapp
PORTVERSION=	0.6.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern style C++ library for working with XML data

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

OPTIONS=	XSLT "build libxsltwrap library (requires libxslt)" off

CONFIGURE_ARGS=	--prefix ${PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
USE_AUTOTOOLS=	libtool
USE_GNOME=	libxml2 pkgconfig gnomehack
USE_PERL5_BUILD=	yes
USE_LDCONFIG=	yes
WANT_GNOME=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if defined(WITH_XSLT)
USE_GNOME+=	libxslt
.else
CONFIGURE_ARGS+=--disable-xslt
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} 's/docs//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
