# New ports collection makefile for:	mod_cvs
# Date created:				14 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	mod_cvs
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.sub.nu/pub/mod_cvs/ \
		ftp://ftp.isk.kth.se/pub/people/main/mod_cvs/

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

MAKE_ARGS+=	APXS="${APXS}"

APXS?=	${LOCALBASE}/sbin/apxs

post-patch:
	@${PERL} -pi -e 's,apxs,${APXS},g' ${WRKSRC}/Makefile

do-install:
	${APXS} -i -A -n cvs ${WRKSRC}/mod_cvs.so
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
