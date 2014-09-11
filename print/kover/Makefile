# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kover
PORTVERSION=	6
PORTREVISION=	4
CATEGORIES=	print kde
MASTER_SITES=	http://lisas.de/kover/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG CD cover printer

LICENSE=	GPLv2

LIB_DEPENDS=	libcddb.so:${PORTSDIR}/audio/libcddb \
		libcdio.so:${PORTSDIR}/sysutils/libcdio

USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5=	build
USES=		cmake gettext perl5 pkgconfig shared-mime-info tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e \
		'/libcdio/s|>=.*)|)|' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
