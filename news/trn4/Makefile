# Created by: smace
# $FreeBSD$

PORTNAME=	trn
PORTVERSION=	4.0.b77
PKGNAMESUFFIX=	4
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}4
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-test/}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Version 4.0 of the threaded readnews newsreader

CONFLICTS_INSTALL=trn-3.[0-9]* cnews-* s-news-[0-9]*

USES=		ncurses

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's/pipe[12]/z&/g' ${WRKSRC}/filter.c
	${REINPLACE_CMD} -e 's|^dir=|&$${DESTDIR}|' ${WRKSRC}/myinstall.SH
	${REINPLACE_CMD} -e 's|./makedir |&$${DESTDIR}|' \
		-e 's|dest=|&$${DESTDIR}|' ${WRKSRC}/Makefile.SH

pre-configure:
	@${ECHO_MSG} "===>  Running pre-configure target for ${DISTNAME}"
	@${SED} -e "s:__CC__:${CC}:" -e "s:__CFLAGS__:${CFLAGS}:" \
		-e "s:/PREFIX:${PREFIX}:"  ${SCRIPTDIR}/preconf > \
		${WRKDIR}/preconf.new
.ifdef BATCH
	@${ECHO_CMD} 3 | ${SH} ${WRKDIR}/preconf.new ${PORTSDIR} ${.CURDIR} ${WRKSRC}
.else
	@${SH} ${WRKDIR}/preconf.new ${PORTSDIR} ${.CURDIR} ${WRKSRC}
.endif

.include <bsd.port.post.mk>
