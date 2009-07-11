# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#    $MCom: ports/www/nvu/Makefile,v 1.5 2006/07/18 15:07:36 ahze Exp $
#

PORTNAME=	nvu
DISTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-sources

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	A complete Web Authoring System similar to Dreamweaver or Frontpage

DEPRECATED=	NVU 1.0, released June 2005, is the last official release of NVU. \
		Kompozer has picked up where NVU has left off. Please consider using \
		${PORTSDIR}/www/kompozer instead

USE_BZIP2=	yes
WANT_GNOME=	yes
WANT_PERL=	yes
USE_GMAKE=	yes
NVU=		${PORTNAME}-${DISTVERSION}
MAKEFILE=	client.mk
ALL_TARGET=	build_all
MOZ_EXTENSIONS=	wallet,xml-rpc,xmlextras,pref,universalchardet,editor/cascades,spellcheck
PORT_MOZCONFIG=	${WRKSRC}/composer/config/mozconfig.linux
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/Makefile.common"

.if ${ARCH} == "ia64"
BROKEN=		does not build
.endif

.if ${ARCH}=="amd64"
.if ${OSVERSION} >= 700042
BROKEN=		does not build
.endif
.endif

.if ${ARCH}=="sparc64"
.if ${OSVERSION} < 601101 || ${OSVERSION} >= 700042
IGNORE=		does not build
.endif
.endif

post-patch:
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/gnome/Makefile.in

.include <bsd.port.post.mk>
