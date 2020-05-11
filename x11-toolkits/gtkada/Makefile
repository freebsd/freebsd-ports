# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	2.24.4.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gtkada-rm-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada graphical toolkit based on Gtk2+

LICENSE=	GPLv2

USES=		ada gmake gnome perl5 pkgconfig tar:bzip2
USE_PERL5=	build
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
ALL_TARGET=	src
NO_MTREE=	yes
PORTDOCS=	gtkada_rm gtkada_ug
PORTEXAMPLES=	*

MAKE_ENV+=	PROCESSORS=${MAKE_JOBS_NUMBER}

CONFLICTS_INSTALL=	gtkada3-*

PORTSCOUT=		ignore:1

OPTIONS_DEFINE=		DOCS NLS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build-2.7:textproc/py-sphinx18@py27
BINARY_ALIAS+=	sphinx-build=sphinx-build-2.7
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
USES+=			gettext
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+= docs
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
ALL_TARGET+= tests
.endif

post-patch:
	# fix for gcc-5
	@${REINPLACE_CMD} -e 's|inline gint roundint|gint roundint|' \
		${WRKSRC}/src/gtkextra/gtkplot*

do-build:
#	This target is recreated because -j cannot be set, but
#	MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources

.include <bsd.port.mk>
