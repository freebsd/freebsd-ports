# $FreeBSD$

PORTNAME=	queue-fix
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.netmeridian.com/e-huss/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Repairs or generates a qmail queue structure

USES=		qmail:run


PREFIX?=	${QMAIL_PREFIX}

OPTIONS_DEFINE=	DOCS BIG_TODO

BIG_TODO_DESC=	Use big_todo patch

CONFIGURE_SCRIPT=
ALL_TARGET=

PLIST_FILES=	bin/queue-fix

PORTDOCS=	README

.include <bsd.port.pre.mk>

.if (${PREFIX} == ${LOCALBASE})
DOCSDIR=	${PREFIX}/share/doc/qmail/queue-fix
.else
DOCSDIR=	${PREFIX}/doc/queue-fix
.endif

.if ${PORT_OPTIONS:MBIG_TODO}
PATCH_SITES+=		http://www.qmail.org/
PATCHFILES+=		queue-fix-todo.patch
PATCH_DIST_STRIP+=	-p1
.endif

post-patch:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
