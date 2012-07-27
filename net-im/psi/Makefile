# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.14
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/Psi/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A Qt-based Jabber client

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca
RUN_DEPENDS=	qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl \
		qca-gnupg>=2.0.0.b3:${PORTSDIR}/security/qca-gnupg

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_QT4=	corelib dbus gui iconengines imageformats qt3support \
		inputmethods network script svg xml \
		qmake_build moc_build rcc_build uic_build

CONFIGURE_ARGS=	--prefix=${PREFIX} --qtdir=${LOCALBASE} \
		--disable-growl --disable-bundled-qca \
		--verbose

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	ASPELL ENCHANT
OPTIONS_DEFAULT=	ASPELL

ASPELL_DESC=	Use aspell for spell checking
ENCHANT_DESC=	Use Enchant for spell checking

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--debug
PLIST_SUB+=	DEBUG=""
.else
CONFIGURE_ARGS+=	--release  --no-separate-debug-info
PLIST_SUB+=	DEBUG="@comment "
.endif

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-aspell-inc=${LOCALBASE}/include \
			--with-aspell-lib=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-aspell
.endif

.if ${PORT_OPTIONS:MENCHANT}
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
.else
CONFIGURE_ARGS+=	--disable-enchant
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/psi

.include <bsd.port.mk>
