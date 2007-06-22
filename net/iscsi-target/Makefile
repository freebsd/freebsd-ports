# New ports collection makefile for:	iscsi-target
# Date created:				2006-04-18
# Whom:					Frederic Senault <fred@lacave.net>
#
# $FreeBSD$
#

PORTNAME=	iscsi-target
PORTVERSION=	20070615
CATEGORIES=	net
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/
DISTNAME=	netbsd-iscsi-${PORTVERSION}

MAINTAINER=	mark@foster.cc
COMMENT=	Implementation of userland ISCSI target (derived from NetBSD)

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN5=		targets.5
MAN8=		iscsi-target.8

USE_RC_SUBR=	iscsi_target

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		needs PRIu64 definition in <inttypes.h>
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|_LDFLAGS= -pthread|_LDFLAGS= ${PTHREAD_CFLAGS}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|_FLAGS= -pthread|_FLAGS= ${PTHREAD_CFLAGS}|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/iscsi-target ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/iscsi
.for i in targets passwd auths
	${INSTALL_DATA} ${WRKSRC}/etc/$i ${PREFIX}/etc/iscsi/$i.sample
.endfor
	${INSTALL_MAN} ${WRKSRC}/targets.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/iscsi-target.8 ${PREFIX}/man/man8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in FAQ README README_OSD PERFORMANCE license
	${INSTALL_MAN} ${WRKSRC}/../doc/$i ${DOCSDIR}
.endfor
.endif
.for i in targets passwd auths
	if [ ! -f ${PREFIX}/etc/iscsi/$i ]; then \
		${CP} -p ${PREFIX}/etc/iscsi/$i.sample ${PREFIX}/etc/iscsi/$i ; \
	fi
.endfor

.include <bsd.port.post.mk>
