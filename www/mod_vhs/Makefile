# New ports collection makefile for:	mod_vhs
# Date created:				Sun Jul 25 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_vhs
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.oav.net/projects/mod_vhs/
DIST_SUBDIR=	apache

MAINTAINER=	kiwi@oav.net
COMMENT=	Allows mass virtual hosting using libhome system with Apache 2.0.x

LIB_DEPENDS+=	home:${PORTSDIR}/misc/libhome

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

AP_INC+=	${LOCALBASE}/include/home
AP_LIB+=	${LOCALBASE}/lib -lhome

PORTDOCS=	AUTHORS README TODO

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
