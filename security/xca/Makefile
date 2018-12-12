# Created by: Valentin Zahariev <curly@e-card.bg>
# $FreeBSD$

PORTNAME=	xca
PORTVERSION=	2.1.2
PORTREVISION=	1
DISTVERSIONPREFIX=	RELEASE.
CATEGORIES=	security

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Graphical certification authority

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf compiler:c++11-lang desktop-file-utils gmake \
		localbase pkgconfig qt:5 shared-mime-info shebangfix ssl
USE_QT=		buildtools_build core gui linguist_build sql widgets
USE_CXXSTD=	c++11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLDIR} \
		--with-qt=${PREFIX} \
		--with-qt-version=5
MAKE_ARGS=	DOCTOOL="${TRUE}"
DESTDIRNAME=	destdir
SHEBANG_FILES=	doc/code2html

USE_GITHUB=	yes
GH_ACCOUNT=	chris2511

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|-O2||' ${WRKSRC}/Local.mak.in
	@${REINPLACE_CMD} -e \
		'/install/s|-D|-c|' ${WRKSRC}/img/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xca*

.include <bsd.port.mk>
