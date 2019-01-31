# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	44bsd-rdist
PORTVERSION=	20001111
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The traditional 4.4BSD rdist

EXTRACT_DEPENDS=    rcs:devel/rcs57

USES=		tar:bzip2

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/44bsd-rdist \
		man/man1/44bsd-rdist.1.gz

post-extract:
	cd ${WRKSRC} ; co RCS/*,v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdist ${STAGEDIR}${PREFIX}/bin/44bsd-rdist
	${INSTALL_MAN} ${WRKSRC}/rdist.1 ${STAGEDIR}${PREFIX}/man/man1/44bsd-rdist.1

tarup:
	-cd ${WRKSRC} ; ${RM} *
	cd ${WRKSRC} ; ${TAR} cvyf /tmp/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} .

.include <bsd.port.mk>
