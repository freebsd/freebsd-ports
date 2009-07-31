# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
DISTVERSION=	0.12.1
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A Qt-based Jabber client

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl \
		qca-gnupg>=2.0.0.b3:${PORTSDIR}/security/qca-gnupg

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui iconengines imageformats qt3support \
		inputmethods network script svg xml \
		qmake_build moc_build rcc_build uic_build

CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${LOCALBASE} \
		--disable-growl --disable-ghbnr --disable-bundled-qca

post-patch:
#fix build when libzip is installed
	cd ${WRKSRC}/src/tools/zip && ${LN} zip.h psi-zip.h

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi

.include <bsd.port.mk>
