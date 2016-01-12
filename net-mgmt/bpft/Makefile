# Created by: El Vampiro <vampiro@rootshell.ru>
# $FreeBSD$

PORTNAME=	bpft
PORTVERSION=	4.20040506
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}4/${PORTNAME}4/${PORTNAME}4-snapshot
DISTNAME=	${PORTNAME}4-2004-05-06

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BPF Traffic collector

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.GNU

CONFLICTS=	trafd-3.0.*

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	INSTALL_FILE="${INSTALL_DATA}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|g' ${WRKSRC}/include/pathnames.h
	@${REINPLACE_CMD} -e \
		'/^PATH_TOSAVE/s|=.*|= ${PREFIX}/var/bpft| ; \
		 /^INSTALL_DIRECTORY/s|=.*|= ${MKDIR}| ; \
		 s|please!|&"| ; \
		 s| $${PATH_| $${DESTDIR}$${PATH_|g ; \
		 s| $${PREFIX_| $${DESTDIR}$${PREFIX_|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|bpf_dump.[co]||' ${WRKSRC}/lib/Makefile
	@${REINPLACE_CMD} -e \
		's|<net/slip.h>|"../linux-include/net/slip.h"|' \
		${WRKSRC}/lib/interfaces.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README WhatsNew
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
