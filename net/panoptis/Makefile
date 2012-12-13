# New ports collection makefile for:	panoptis
# Date created:		2006-11-28
# Whom:			Babak Farrokhi <farrokhi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	panoptis
PORTVERSION=	0.1.4
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Detect and block DoS/DDoS attacks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	ccgnu2:${PORTSDIR}/devel/commoncpp

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
PLIST_FILES=	bin/panoptis \
		bin/mail.py \
		bin/pview.py \
		bin/speed.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/panoptis/panoptis ${PREFIX}/bin/panoptis
.for f in mail.py pview.py speed.py
	${INSTALL_SCRIPT} ${WRKSRC}/panoptis/${f} ${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
