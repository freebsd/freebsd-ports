# Created by: hbo@egbok.com
# $FreeBSD$

PORTNAME=	sudoscript
PORTVERSION=	2.1.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%202.1%20release/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audited shells in Perl with sudo(8) and script(1)

MAN1=		ss.1 sudoshell.1
MAN3=		Sudoscript.3pm
MAN8=		sudoscriptd.8 sudoscript.8
MANCOMPRESSED=	no

USE_GMAKE=	yes
USES=		perl5

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX=|^PREFIX?=|g' \
	${WRKSRC}/Makefile

.include <bsd.port.mk>
