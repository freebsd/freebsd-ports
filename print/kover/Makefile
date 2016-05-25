# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kover
PORTVERSION=	6
PORTREVISION=	6
CATEGORIES=	print kde
MASTER_SITES=	https://lisas.de/kover/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG CD cover printer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcddb.so:audio/libcddb \
		libcdio.so:sysutils/libcdio

USE_KDE4=	automoc4 kdelibs
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5=	build
USES=		cmake gettext perl5 pkgconfig shared-mime-info tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e \
		'/libcdio/s|>=.*)|)|' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
