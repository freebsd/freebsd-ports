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
PORTREVISION=	5
CATEGORIES=	www editors
MASTER_SITES=	http://fossies.org/unix/www/old/ \
		http://www.sourcefiles.org/Editors/HTML/ \
		http://www.erjobe.info/mainwiki/pmwiki/uploads/Main/August/
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor for the experienced Web author

LICENSE=	GPLv2

RUN_DEPENDS=	identify:${PORTSDIR}/graphics/ImageMagick \
		weblint:${PORTSDIR}/www/weblint

NO_BUILD=	yes

USE_TK_WRAPPER=	yes

PORTDOCS=	specchars.txt
PLIST_FILES=	bin/august

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin|${LOCALBASE}/bin|g' ${WRKSRC}/august

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/august ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/specchars.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
