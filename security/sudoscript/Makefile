# New ports collection makefile for:   sudoscript
# Date created:        17 June, 2003
# Whom:                hbo@egbok.com
#
# $FreeBSD$
#

PORTNAME=	sudoscript
PORTVERSION=	2.1.2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audited shells in Perl with sudo(8) and script(1)

MAN1=		ss.1 sudoshell.1
MAN3=		Sudoscript.3pm
MAN8=		sudoscriptd.8 sudoscript.8
MANCOMPRESSED=	no

USE_GMAKE=	yes
USE_PERL5=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX=|^PREFIX?=|g' \
	${WRKSRC}/Makefile

.include <bsd.port.mk>
