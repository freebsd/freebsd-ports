# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	44bsd-rdist
PORTVERSION=	20001111
CATEGORIES=	net
MASTER_SITES=	LOCAL/cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The traditional 4.4BSD rdist


USES=		tar:bzip2

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/44bsd-rdist \
		man/man1/44bsd-rdist.1.gz

.include <bsd.port.pre.mk>

.if  ${OSVERSION} >= 1000055
BUILD_DEPENDS=    rcs:devel/rcs57
.endif

post-extract:
	cd ${WRKSRC} ; co RCS/*,v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdist ${STAGEDIR}${PREFIX}/bin/44bsd-rdist
	${INSTALL_MAN} ${WRKSRC}/rdist.1 ${STAGEDIR}${PREFIX}/man/man1/44bsd-rdist.1

tarup:
	-cd ${WRKSRC} ; ${RM} *
	cd ${WRKSRC} ; ${TAR} cvyf /tmp/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} .

.include <bsd.port.post.mk>
