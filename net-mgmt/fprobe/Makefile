# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	fprobe
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that collects network traffic data

USES=		tar:bzip2
USE_RC_SUBR=	fprobe
GNU_CONFIGURE=	yes
SUB_LIST=	NAME=${PORTNAME}
PLIST_FILES=	man/man8/${PORTNAME}.8.gz sbin/fprobe
PORTDOCS=	ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
