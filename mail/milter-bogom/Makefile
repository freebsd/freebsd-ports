# Created by: Victor Balada Diaz <victor@bsdes.net>
# $FreeBSD$

PORTNAME=	bogom
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.usebox.net/jjm/bogom/ \
		http://blackshell.usebox.net/bogom/
PKGNAMEPREFIX=	milter-

MAINTAINER=	victor@bsdes.net
COMMENT=	Simple sendmail milter to interface bogofilter

RUN_DEPENDS=	bogofilter:${PORTSDIR}/mail/bogofilter

MAKE_ARGS=	CPPFLAGS="-DDEF_CONF=\\\"${PREFIX}/etc/bogom.conf\\\" ${PTHREAD_CFLAGS}" \
		LIBS="-lmilter ${PTHREAD_LIBS}"

USE_RC_SUBR=	milter-bogom
SUB_FILES=	pkg-message

PLIST_FILES=	sbin/bogom \
		man/man8/bogom.8.gz \
		etc/bogom.conf-example

PORTDOCS=	README CHANGELOG

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/bogom.8
	${REINPLACE_CMD} -e \
		's|/usr/local/bin/bogofilter|${LOCALBASE}/bin/bogofilter|g' \
		${WRKSRC}/bogom.8 \
		${WRKSRC}/bogom.conf-example \
		${WRKSRC}/milter.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bogom ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/bogom.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/bogom.conf-example ${STAGEDIR}${PREFIX}/etc/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
