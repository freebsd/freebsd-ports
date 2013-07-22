# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	confetti
PORTVERSION=	0.0.${DATE}
CATEGORIES=	textproc
MASTER_SITES=	http://fbsd.zlonet.ru/distfiles/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Configuration file parser generator

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		bison
USE_PERL5=	yes
DATE=		20120801
MAKE_ARGS+=	FLEX=${LOCALBASE}/bin/flex
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CC=|CC?=|' -e 's|CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} example ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
