# New ports collection makefile for:	hourglass
# Date created:		23 March 2004
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	hourglass
PORTVERSION=	1.0.1
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.cs.utah.edu/~regehr/hourglass/
DISTNAME=	${PORTNAME}-${PORTVERSION}b

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A real-time application useful to learn how CPU scheduling works

RUN_DEPENDS=	jgraph:${PORTSDIR}/graphics/jgraph

ONLY_FOR_ARCHS=	i386 amd64
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/busy bin/hourglass
PORTDOCS=	CALIBRATION

.include <bsd.port.pre.mk>

.if defined(WITH_LINUXTHREADS)

.if ${OSVERSION} >= 500035
PTHREAD_LIBS=	-L${LOCALBASE}/lib -llthread -llgcc_r
PTHREAD_CFLAGS=	-D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads
LIB_DEPENDS+=	lthread.3:${PORTSDIR}/devel/linuxthreads
.else
LIB_DEPENDS+=	lthread.2:${PORTSDIR}/devel/linuxthreads
.endif

.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALBASE%,${LOCALBASE},g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%PTHREAD_LIBS%,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%PTHREAD_CFLAGS%,${PTHREAD_CFLAGS},g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
