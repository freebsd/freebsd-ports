# New ports collection makefile for:	august
# Date created:				2000-12-31
# Whom:					trevor
#
# based on the OpenBSD port by Kevin Lo <kevlo@openbsd.org>
# $OpenBSD: Makefile,v 1.6 2000/12/10 15:00:14 kevlo Exp $
# $FreeBSD$
#

PORTNAME=	august
PORTVERSION=	0.63b
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	http://www.bostream.nu/johanb/august/
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor for the experienced Web author

RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint \
		identify:${PORTSDIR}/graphics/ImageMagick \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

do-patch:
	${MV} ${WRKSRC}/august ${WRKSRC}/august.orig
	${SED} -e "s:/usr/bin/wish:${PREFIX}/bin/wish8.4:g" \
		< ${WRKSRC}/august.orig > ${WRKSRC}/august

pre-install:
	${ECHO_CMD} bin/august > ${PLIST}
.if !defined(NOPORTDOCS)
	${ECHO_CMD} share/doc/august/specchars.txt >> ${PLIST}
	${ECHO_CMD} @dirrm share/doc/august >> ${PLIST}
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/august ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/august
	${INSTALL_DATA} ${WRKSRC}/specchars.txt ${PREFIX}/share/doc/august
.endif

.include <bsd.port.mk>
