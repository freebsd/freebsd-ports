PORTNAME=	timbl
DISTVERSION=	6.10
PORTREVISION=	2
CATEGORIES=	math education
MASTER_SITES=	https://github.com/LanguageMachines/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tilburg Memory Based Learner
WWW=		https://ilk.uvt.nl/timbl/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libticcutils.so:devel/ticcutils

USES=		compiler:c++14-lang gmake gnome libtool pathfix pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

TEST_TARGET=	check
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -g||g' \
		${PATCH_WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
