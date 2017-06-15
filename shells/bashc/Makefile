# Created by: alepulver
# $FreeBSD$

PORTNAME=	bashc
PORTVERSION=	3.2.33.0
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU bash shell extended with visual two-panel file browser

MAKE_JOBS_UNSAFE=	yes

BROKEN_aarch64=		Fails to link: missing sbrk

USES=		tar:tgz
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|autoconf|${TRUE}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
