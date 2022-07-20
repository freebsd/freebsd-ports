PORTNAME=	xca
PORTVERSION=	2.4.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/xca/releases/download/RELEASE.${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Graphical certification authority

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		compiler:c++11-lang desktop-file-utils gmake localbase \
		pkgconfig qt:5 shared-mime-info ssl
USE_QT=		buildtools_build core gui help linguist_build sql widgets
USE_CXXSTD=	c++11

GNU_CONFIGURE=	yes
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--with-openssl=${OPENSSLDIR} \
		--with-qt=${PREFIX} \
		--with-qt-version=5

GH_ACCOUNT=	chris2511

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s|-O2 ||' \
		${WRKSRC}/Local.mak.in

.include <bsd.port.mk>
