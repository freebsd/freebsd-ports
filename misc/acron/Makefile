# New ports collection makefile for:    acron
# Date created:         13 Dec 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acron
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/others/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s|\@\@PREFIX\@\@|${PREFIX}|g;" ${WRKSRC}/whats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/whats ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/whats ${PREFIX}/bin/acron
	${INSTALL_DATA} ${WRKSRC}/acron ${PREFIX}/share/misc

.include <bsd.port.mk>
