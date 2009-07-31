# Ports collection makefile for:	emacs-calc
# Date created:		7/10/5
# Whom:			andrewb@cs.cmu.edu
#
# $FreeBSD$
#

PORTNAME=	calc
PORTVERSION=	2.02f
PORTREVISION=	3
CATEGORIES=	math editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	emacs-

MAINTAINER=	andrewb@cs.cmu.edu
COMMENT=	Arbitrary-precision calculator for Emacs

CONFLICTS=	emacs-22.* xemacs-packages-\*

USE_EMACS=	yes
EMACS_PORT_NAME=emacs21

INFO=		calc

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
