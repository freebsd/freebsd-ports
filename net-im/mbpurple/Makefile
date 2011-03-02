# New ports collection makefile for:	mbpurple
# Date created:				30 June 2010
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mbpurple
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Integrate twitter with pidgin (AKA microblog-purple)

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS:=	${BUILD_DEPENDS}

PROJECTHOST=	microblog-purple
USE_GMAKE=	yes
USE_GNOME=	pkgconfig

post-patch:
	@${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.Dist
	@${SED} -e 's#make -C#gmake -C#' \
		${WRKSRC}/Makefile.Dist > ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/global.mak ${WRKSRC}/global.mak.Dist
	@${SED} -e 's#^PREFIX :=.*#PREFIX = ${PREFIX}#' \
		-e 's#^LIBDIR :=.*#LIBDIR = ${LOCALBASE}/lib#' \
		-e 's#^PURPLE_PLUGIN_DIR :=.*#PURPLE_PLUGIN_DIR = ${PREFIX}/lib/purple-2#' \
		-e 's#^PURPLE_CACERTS_DIR :=.*#PURPLE_CACERTS_DIR = ${PREFIX}/share/purple/ca-certs#' \
		${WRKSRC}/global.mak.Dist > ${WRKSRC}/global.mak

do-build:
	cd ${WRKSRC} && ${GMAKE}

.include <bsd.port.mk>
