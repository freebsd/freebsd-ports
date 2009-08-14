# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.13
CATEGORIES=	net-im
MASTER_SITES=	SFP/${PORTNAME}/Psi/${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A Qt-based Jabber client

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca \
		aspell.16:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl \
		qca-gnupg>=2.0.0.b3:${PORTSDIR}/security/qca-gnupg

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui iconengines imageformats qt3support \
		inputmethods network script svg xml \
		qmake_build moc_build rcc_build uic_build

CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${LOCALBASE} \
		--with-aspell-inc=${LOCALBASE}/include \
		--with-aspell-lib=${LOCALBASE}/lib \
		--disable-growl --disable-ghbnr --disable-bundled-qca \
		--verbose

MAKE_JOBS_SAFE=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi

.include <bsd.port.mk>
