# Created by: Valentin Zahariev <curly@e-card.bg>
# $FreeBSD$

PORTNAME=	xca
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical certification authority

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl

USES=		desktop-file-utils gmake localbase pkgconfig shared-mime-info
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLDIR} \
		--with-qt=${QT_PREFIX}
MAKE_ARGS=	DOCTOOL="${TRUE}"
DESTDIRNAME=	destdir

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT4

QT4_USE=		qt4=gui,linguist_build,moc_build,qmake_build \
			qt4=rcc_build,uic_build
QT5_USE=		qt5=widgets,buildtools_build,linguist_build
TOOLKIT_DESC=		Qt toolkit

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|-O2||' ${WRKSRC}/Local.mak.in
	@${REINPLACE_CMD} -e \
		'/install/s|-D|-c|' ${WRKSRC}/img/Makefile

post-patch-QT5-off:
	@${REINPLACE_CMD} -e \
		's|Qt5|Qt0|g' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xca*

.include <bsd.port.mk>
