# New ports collection makefile for:	panoptis
# Date created:		2006-11-28
# Whom:			Babak Farrokhi <farrokhi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	panoptis
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Detect and block DoS/DDoS attacks

LIB_DEPENDS=	ccgnu2-1.6.0:${PORTSDIR}/devel/commoncpp

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}' LDFLAGS='${LDFLAGS}'
PLIST_FILES=	bin/panoptis bin/mail.py bin/pview.py bin/speed.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/panoptis/panoptis ${PREFIX}/bin/panoptis
.for f in mail.py pview.py speed.py
	${INSTALL_SCRIPT} ${WRKSRC}/panoptis/mail.py ${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
