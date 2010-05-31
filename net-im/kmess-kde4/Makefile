# New ports collection makefile for:	kmess
# Date created:			21 June 2002
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	kmess
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	net-im kde
MASTER_SITES=	SF/${PORTNAME}/Latest%20versions/${PORTVERSION}/

MAINTAINER=	syncer@gmail.com
COMMENT=	MSN Messenger client for KDE

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		qca.2:${PORTSDIR}/devel/qca
BUILD_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl

LATEST_LINK=	${PORTNAME}-kde4
MAKE_JOBS_SAFE=	yes
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdehier kdeprefix kdebase automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network opengl script svg webkit \
		qmake_build moc_build rcc_build uic_build phonon
USE_CMAKE=	yes
USE_GETTEXT=	yes

.include <bsd.port.mk>
