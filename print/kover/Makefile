# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kover
PORTVERSION=	6
CATEGORIES=	print kde
MASTER_SITES=	http://lisas.de/kover/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG CD cover printer

LICENSE=	GPLv2

LIB_DEPENDS=	cddb:${PORTSDIR}/audio/libcddb \
		cdio:${PORTSDIR}/sysutils/libcdio

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs sharedmime
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5=	build
USES=		cmake gettext perl5 pkgconfig

MAN1=		kover.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/libcdio/s|>=.*)|)|' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
