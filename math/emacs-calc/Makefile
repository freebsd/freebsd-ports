# Created by: andrewb@cs.cmu.edu
# $FreeBSD$

PORTNAME=	calc
PORTVERSION=	2.02f
PORTREVISION=	6
CATEGORIES=	math editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	emacs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arbitrary-precision calculator for Emacs

CONFLICTS=	emacs-22.* xemacs-packages-\*

USE_EMACS=	yes
EMACS_PORT_NAME=emacs21

INFO=		calc

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
