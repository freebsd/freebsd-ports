# New ports collection makefile for:	hourglass
# Date created:		23 March 2004
# Whom:			olive
#
# $FreeBSD$
#

PORTNAME=	hourglass
PORTVERSION=	1.0.0
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.cs.utah.edu/~regehr/hourglass/

MAINTAINER=	olive@oban.frmug.org
COMMENT=	A real-time application useful to learn how CPU scheduling works

RUN_DEPENDS=	jgraph:${PORTSDIR}/graphics/jgraph

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/busy bin/hourglass
PORTDOCS=	CALIBRATION

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
LIB_DEPENDS+=	lthread.3:${PORTSDIR}/devel/linuxthreads
.else
LIB_DEPENDS+=	lthread.2:${PORTSDIR}/devel/linuxthreads
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALBASE%,${LOCALBASE},g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
