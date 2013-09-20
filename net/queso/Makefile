# Created by: Wu Ching-hong <woju@freebsd.ee.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	queso
PORTVERSION=	980922
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	PACKETSTORM/UNIX/scanners

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine the remote OS using simple TCP packets

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2 -pipe|| ; \
		 s|^LDFLAGS|#LDFLAGS|' ${WRKSRC}/Makefile.in
	@${LN} -sf queso.conf ${WRKSRC}/queso.conf.sample

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} queso ${PREFIX}/sbin)
	(cd ${WRKSRC} && ${INSTALL_DATA} queso.conf.sample ${PREFIX}/etc)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} Documentation.txt ${DOCSDIR})
.endif

.include <bsd.port.mk>
