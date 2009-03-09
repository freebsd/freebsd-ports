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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Detect and block DoS/DDoS attacks

LIB_DEPENDS=	ccgnu2-1.6.0:${PORTSDIR}/devel/commoncpp

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}' LDFLAGS='${LDFLAGS}'
PLIST_FILES=	bin/panoptis bin/mail.py bin/pview.py bin/speed.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/panoptis/panoptis ${PREFIX}/bin/panoptis
	${INSTALL_SCRIPT} ${WRKSRC}/panoptis/mail.py ${PREFIX}/bin/mail.py
	${INSTALL_SCRIPT} ${WRKSRC}/panoptis/pview.py ${PREFIX}/bin/pview.py
	${INSTALL_SCRIPT} ${WRKSRC}/panoptis/speed.py ${PREFIX}/bin/speed.py

.include <bsd.port.mk>
