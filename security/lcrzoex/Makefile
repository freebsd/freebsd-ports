# New ports collection makefile for:	lcrzoex
# Date created:		Wed Apr 10 02:42:20 CEST 2002
# Whom:			king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	lcrzoex
PORTVERSION=	4.17.0
CATEGORIES=	security
MASTER_SITES=	http://www.laurentconstantin.com/common/lcrzoex/download/v4/ \
		http://www.mirrors.wiretapped.net/security/packet-construction/lcrzoex/ \
		ftp://ftp.mirrors.wiretapped.net/sd3a/security/packet-construction/lcrzoex/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	king@v2project.com

BUILD_DEPENDS=	${LOCALBASE}/lib/liblcrzo.a:${PORTSDIR}/security/lcrzo

WRKSRC=		${WRKDIR}/${PKGNAME}-src/src

MAN1=	lcrzoex.1

post-patch:
	cd ${WRKSRC} && ${SH} ${WRKSRC}/genemake

post-install:
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.mk>
