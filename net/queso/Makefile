# Created by: Wu Ching-hong <woju@freebsd.ee.ntu.edu.tw>

PORTNAME=	queso
PORTVERSION=	980922
PORTREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	PACKETSTORM/UNIX/scanners

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine the remote OS using simple TCP packets

LICENSE=	GPLv2

DEPRECATED=	Abandonware and obsolete, last release back in 1998. Please consider using security/nmap instead
EXPIRATION_DATE=2022-03-31

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2 -pipe|| ; \
		 s|^LDFLAGS|#LDFLAGS|' ${WRKSRC}/Makefile.in
	@${LN} -sf queso.conf ${WRKSRC}/queso.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queso ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/queso.conf.sample ${STAGEDIR}${PREFIX}/etc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
