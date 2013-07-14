# $FreeBSD$

PORTNAME=	rekonq
PORTVERSION=	2.3.2
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:C,\..*,.0,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Lightweight KDE browser based on WebKit

USE_BZIP2=	yes
USES=		cmake:outsource
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	script webkit \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	OPERA NEPOMUK
OPTIONS_DEFAULT=	NEPOMUK
OPERA_DESC=	Support for Opera Sync service
NEPOMUK_DESC=	Bookmarks tagging via Nepomuk

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's,FIND_PACKAGE(NepomukCore,MACRO_OPTIONAL_FIND_PACKAGE(NepomukCore,' \
		${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MNEPOMUK}
USE_KDE4+=	nepomuk-core
.else
CMAKE_ARGS+=	-DWITH_NepomukCore=off
.endif

.if ${PORT_OPTIONS:MOPERA}
LIB_DEPENDS+=	qca.2:${PORTSDIR}/devel/qca \
		qoauth.1:${PORTSDIR}/net/qoauth
.else
CMAKE_ARGS+=	-DWITH_QCA2=off \
		-DWITH_QtOAuth=off
.endif

.include <bsd.port.mk>
