# Created by: Steven Kreuzer <steven@exit2shell.com>
# $FreeBSD$

PORTNAME=	DTraceToolkit
PORTVERSION=	0.99
CATEGORIES=	sysutils
MASTER_SITES=	http://www.brendangregg.com/ \
		http://mirror.transact.net.au/sourceforge/d/dt/dtracetoolkit/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of useful scripts for DTrace

NO_BUILD=	YES

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 701000
IGNORE=	needs to have dtrace enabled kernel
.endif

pre-patch:
	${REINPLACE_CMD} -e \
		"s|\#\!/usr/bin/perl|\#\!${PREFIX}/bin/perl|g" \
		${WRKSRC}/hotkernel

	${REINPLACE_CMD} -e \
		"s|\#\!/usr/bin/sh|\#\!/bin/sh|g" \
		${WRKSRC}/procsystime

do-install:
	${RM} ${WRKSRC}/hotkernel.bak
	${RM} ${WRKSRC}/procsystime.bak
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}; ${TAR} cf - . ) | \
		(cd ${DATADIR}/; ${TAR} xvf -)
	${LN} -fs ${DATADIR}/hotkernel ${PREFIX}/bin/hotkernel
	${LN} -fs ${DATADIR}/procsystime ${PREFIX}/bin/procsystime

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
