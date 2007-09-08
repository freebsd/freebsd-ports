# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#    $MCom: ports/www/nvu/Makefile,v 1.5 2006/07/18 15:07:36 ahze Exp $
#

PORTNAME=	nvu
DISTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-sources

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A complete Web Authoring System similar to Dreamweaver or Frontpage

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
NVU=		${PORTNAME}-${DISTVERSION}
MAKEFILE=	client.mk
ALL_TARGET=	build_all
MOZ_EXTENSIONS=	wallet,xml-rpc,xmlextras,pref,universalchardet,editor/cascades,spellcheck
PORT_MOZCONFIG=	${WRKSRC}/composer/config/mozconfig.linux
CFLAGS+=	-I${X11BASE}/include

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/Makefile.common"

.if ${ARCH} == "ia64"
BROKEN=		does not build
.endif

.if ${ARCH}=="sparc64" && ${OSVERSION} < 601101
IGNORE=		does not build
.endif

post-patch:
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/gnome/Makefile.in

.include <bsd.port.post.mk>
