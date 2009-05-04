# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#    $MCom: ports/www/nvu/Makefile,v 1.5 2006/07/18 15:07:36 ahze Exp $
#

PORTNAME=	kompozer
DISTVERSION=	0.7.10
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${DISTVERSION}dfsg-src

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Complete Web Authoring Suite

WANT_GNOME=	yes
WANT_PERL=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/mozilla
MAKEFILE=	client.mk
ALL_TARGET=	build_all
MOZ_EXTENSIONS=	wallet,xml-rpc,xmlextras,pref,universalchardet,spellcheck
PORT_MOZCONFIG=	${WRKSRC}/composer/config/mozconfig.linux

DESKTOP_ENTRIES="Kompozer" "${COMMENT}" \
		"${PREFIX}/lib/kompozer/icons/mozicon50.xpm" "${PORTNAME}" \
		"Application;Network;" true

NOT_FOR_ARCHS=	ia64 sparc64
NOT_FOR_ARCHS_REASON_ia64=	does not build
NOT_FOR_ARCHS_REASON_sparc64=	crashes in font selection

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/Makefile.common"

post-patch:
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/gnome/Makefile.in

.include <bsd.port.post.mk>
