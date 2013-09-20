# Created by: ntarmos@cs.uoi.gr
# $FreeBSD$

PORTNAME=	unhide
PORTVERSION=	20121229
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A forensic tool to find hidden processes and TCP/UDP ports

NO_WRKSUBDIR=	true
PLIST_FILES=	sbin/unhide sbin/unhide-tcp
MAN8=		unhide.8 unhide-tcp.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's/-eLf/-axH/g' -e 's/$$2/$$1/g' ${WRKDIR}/unhide-posix.c
	@${REINPLACE_CMD} -e 's/linux\/limits/limits/g' ${WRKDIR}/unhide-output.c
	@${REINPLACE_CMD} -e 's/-tan/-p tcp -an/g' -e 's/-uan/-p udp -an/g' \
		-e 's/use_ss = 1/use_ss = 0/g' ${WRKDIR}/unhide-tcp.c

.include <bsd.port.post.mk>
