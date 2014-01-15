# Created by: El Vampiro <vampiro@rootshell.ru>
# $FreeBSD$

PORTNAME=	bpft
PORTVERSION=	4.20040506
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}4/${PORTNAME}4/${PORTNAME}4-snapshot
DISTNAME=	${PORTNAME}4-2004-05-06
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BPF Traffic collector

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS

CONFLICTS=	trafd-3.0.*

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

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

post-install:
.for i in bin/traflog bin/trafstat sbin/trafd sbin/trafstatd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README WhatsNew
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
