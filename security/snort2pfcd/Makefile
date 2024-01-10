PORTNAME=	snort2pfcd
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.tworoutes.com/oss/

MAINTAINER=	onestsam@gmail.com
COMMENT=	Snort alert to pf blocker
WWW=		https://github.com/onestsam/snort2pfcd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcidr.so:devel/libcidr
RUN_DEPENDS=	snort:security/snort

USES=		compiler:c11
USE_RC_SUBR=	snort2pfcd
PLIST_FILES=	share/man/man8/snort2pfcd.8.gz \
		sbin/snort2pfcd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snort2pfcd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/snort2pfcd.8.gz ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
