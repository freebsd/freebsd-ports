# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	rabl_client
PORTVERSION=	1.0.0
CATEGORIES=	mail dns
MASTER_SITES=	http://www.nuclearelephant.com/projects/rabl/sources/ \
		http://sce-tindy.tecnik93.com/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Reactive Autonomous Blackhole List client

GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--localstatedir=${VAR_DIR}

VAR_DIR?=	/var/spool/${PORTNAME}

PORTDOCS=	CHANGE README RELEASE.NOTES

OPTIONS_DEFINE=	DEBUG DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-g -DDEBUG
STRIP_CMD=		# empty
.endif

post-install:
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0640 \
		${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0640 \
		${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
