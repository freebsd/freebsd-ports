# $FreeBSD$

PORTNAME=	rekonq
PORTVERSION=	2.2.1
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

# KDE SC 4.10 is required for Nepomuk support
CMAKE_ARGS+=	-DWITH_NepomukCore=off

OPTIONS_DEFINE=	OPERA
OPERA_DESC=	Support for Opera Sync service

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's,FIND_PACKAGE(NepomukCore,MACRO_OPTIONAL_FIND_PACKAGE(NepomukCore,' \
		${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MOPERA}
LIB_DEPENDS+=	qca.2:${PORTSDIR}/devel/qca \
		qoauth.1:${PORTSDIR}/net/qoauth
.else
CMAKE_ARGS+=	-DWITH_QCA2=off \
		-DWITH_QtOAuth=off
.endif

.include <bsd.port.mk>
