# New ports collection makefile for:	fprobe
# Date created:        			03.06.2003
# Whom:               			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	fprobe
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Tool that collects network traffic data

MAN1=		fprobe.1

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		 ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
