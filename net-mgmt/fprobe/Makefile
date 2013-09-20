# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	fprobe
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that collects network traffic data

GNU_CONFIGURE=	yes
PLIST_FILES=	sbin/fprobe
PORTDOCS=	ChangeLog README
SUB_LIST=	NAME=${PORTNAME}
USE_BZIP2=	yes
USE_RC_SUBR=	fprobe

MAN8=		fprobe.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
