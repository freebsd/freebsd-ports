# Created by: Yuri Victorovich <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	timbl
DISTVERSIONPREFIX=	v
DISTVERSION=	6.4.13
PORTREVISION=	4
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tilburg Memory Based Learner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libticcutils.so:devel/ticcutils

USES=		autoreconf compiler:c++11-lang gmake gnome libtool \
		pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	LanguageMachines
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
