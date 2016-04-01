# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	panoptis
PORTVERSION=	0.1.4
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Detect and block DoS/DDoS attacks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libccgnu2.so:devel/commoncpp

GNU_CONFIGURE=	yes
USES=		python
PLIST_FILES=	bin/panoptis \
		bin/mail.py \
		bin/pview.py \
		bin/speed.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/panoptis/panoptis \
		${STAGEDIR}${PREFIX}/bin/panoptis
.for f in mail.py pview.py speed.py
	${INSTALL_SCRIPT} ${WRKSRC}/panoptis/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
