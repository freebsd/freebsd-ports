# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#    $MCom: ports/www/nvu/Makefile,v 1.3 2005/11/23 00:40:57 ahze Exp $
#

PORTNAME=	nvu
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-sources

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A complete Web Authoring System similar to Dreamweaver or Frontpage

USE_X_PREFIX=	yes
USE_BZIP2=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
NVU=		${PORTNAME}-${DISTVERSION}
MAKEFILE=	client.mk
ALL_TARGET=	build_all
PORT_MOZCONFIG=	${WRKSRC}/composer/config/mozconfig.linux
CFLAGS+=	-I${X11BASE}/include

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../mozilla/Makefile.common"

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN= Does no build
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

post-patch:
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/toolkit/components/gnome/Makefile.in

.include <bsd.port.post.mk>
