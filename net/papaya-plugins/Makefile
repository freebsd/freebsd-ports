# New ports collection makefile for:	papaya-plugins
# Date created:		23 August 2001
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	papaya-plugins
PORTVERSION=	0.90
CATEGORIES=	net
MASTER_SITES=	http://www.gtk-papaya.org/downloads/plugins/source/
DISTNAME=	papaya-plugins-src-${PORTVERSION}

MAINTAINER=	adam+ports@blacktabby.org

# We need the source for papaya to build the plugins.
BUILD_DEPENDS=	${PORTSDIR}/net/papaya/work/papaya-src-${PORTVERSION}/src/h:${PORTSDIR}/net/papaya
RUN_DEPENDS=	papaya:${PORTSDIR}/net/papaya

USE_SUBMAKE=	yes
IS_INTERACTIVE=	yes
USE_GMAKE=	yes
USE_GNOMELIBS=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS+=	CXX="${CXX}"

PLIST=	${WRKSRC}/pkg-plist

post-patch:
	@${PERL} -pi -e 's,g\+\+,${CXX},g' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's,malloc.h,stdlib.h,' ${WRKSRC}/PythonPlugin.cpp \
		${WRKSRC}/TurfProtocol.cpp
	@${PERL} -pi -e 's,stdint.h,sys/types.h,' ${WRKSRC}/SpellStacker.h

pre-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.papaya-plugins
	${RM} ${WRKSRC}/config.cache

post-configure:
	${LN} -fs ${PORTSDIR}/net/papaya/work/papaya-src-${PORTVERSION}/src/h ${WRKSRC}/h

post-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/add-plugins

.include <bsd.port.mk>

.if exists(${WRKDIR}/Makefile.inc)
.include "${WRKDIR}/Makefile.inc"
.endif
