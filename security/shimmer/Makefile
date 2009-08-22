# New ports collection makefile for:	shimmer
# Date created:		2008-01-09
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	shimmer
PORTVERSION=	0.1.0
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Perl implementation that hides a valuable port on your server

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PERL5_RUN=	yes

PLIST_FILES=	bin/shimmer \
		bin/shimmerd \
		etc/shimmer.conf

do-install:
.if !defined(WITHOUT_CLIENT)
	${INSTALL_SCRIPT} ${WRKSRC}/shimmer ${PREFIX}/bin/shimmer
.endif
.if !defined(WITHOUT_SERVER)
	${INSTALL_SCRIPT} ${WRKSRC}/shimmerd ${PREFIX}/bin/shimmerd
	${INSTALL_DATA} ${WRKSRC}/shimmer.conf ${PREFIX}/etc/shimmer.conf
.endif

.include <bsd.port.mk>
