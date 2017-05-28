# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	fwipe
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.jeenyus.net/linux/software/fwipe/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	djb-style file wiping utility

ALL_TARGET=	it
INSTALL_TARGET=	setup
USES=		groff

PLIST_FILES=	bin/fwipe bin/fwipe0 bin/echo0 man/man1/fwipe.1.gz \
		man/man1/fwipe0.1.gz man/man1/echo0.1.gz

post-extract:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home
	@${ECHO_CMD} "${STAGEDIR}${PREFIX}" > ${WRKSRC}/conf-root

.include <bsd.port.mk>
