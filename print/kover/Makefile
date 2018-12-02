# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kover
PORTVERSION=	6
PORTREVISION=	9
CATEGORIES=	print kde
MASTER_SITES=	https://lisas.de/kover/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG CD cover printer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libcddb.so:audio/libcddb \
		libcdio.so:sysutils/libcdio

USES=		cmake gettext kde:4 perl5 pkgconfig qt:4 shared-mime-info tar:bzip2
USE_KDE=	automoc4 kdelibs
USE_QT=		corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5=	build

post-patch:
	@${REINPLACE_CMD} -e \
		'/libcdio/s|>=.*)|)|' ${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
