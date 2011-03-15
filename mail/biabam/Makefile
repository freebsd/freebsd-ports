# New ports collection makefile for:	biabam
# Date created:		03 January 2001
# Whom:			George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	biabam
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://mmj.dk/biabam/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line attachment mailer

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
PLIST_FILES=	bin/biabam

post-patch:
	@${REINPLACE_CMD} -e 's|\(#!\)\(/bin/bash\)|\1${LOCALBASE}\2|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/biabam ${PREFIX}/bin

.include <bsd.port.mk>
