PORTNAME=	rtty
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.isc.org/isc/rtty/ \
		ftp://gatekeeper.research.compaq.com/pub/misc/vixie/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiuser "tip"/"cu" replacement with logging

LICENSE=	MIT

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes

post-install:
	${CHMOD} u+r ${STAGEDIR}${PREFIX}/rtty/bin/*

.include <bsd.port.mk>
