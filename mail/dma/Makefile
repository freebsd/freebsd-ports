# New ports collection makefile for:	dma
# Date created:				2009-01-17
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#
# Based on git checkout from git://gitorious.org/dma/dma.git rather than
# from Dragonfly.
#

PORTNAME=	dma
# commit f54b5114efc65d0e31c7b612bd59cc1b7c8cd8dc
PORTVERSION=	20101004
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=   LOCAL/bz

MAINTAINER=	bz@FreeBSD.org
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

USE_BZIP2=	yes
USE_OPENSSL=	yes
LICENSE=	BSD

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN8=		dma.8

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

USE_RC_SUBR=	dma_flushq
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 700000
BROKEN=	Does not build on 6.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8 \
		${WRKSRC}/dma.h
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf
	@${MV} ${WRKSRC}/BSDmakefile ${WRKSRC}/Makefile

do-install:
	${INSTALL} -o root -g mail -m 2555 ${WRKSRC}/dma ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/dma.8 ${PREFIX}/man/man8/
	${MKDIR} ${PREFIX}/etc/dma
.for i in dma.conf
	${INSTALL_DATA} -m 0644 ${WRKSRC}/${i} ${PREFIX}/etc/dma/${i}.sample
.endfor
	${INSTALL} -o root -g mail -m 0640 ${WRKSRC}/auth.conf \
		${PREFIX}/etc/dma/auth.conf.sample
.for i in dma.conf auth.conf
	if [ ! -f ${PREFIX}/etc/dma/${i} ]; then \
		${CP} -p ${PREFIX}/etc/dma/${i}.sample \
			${PREFIX}/etc/dma/${i} ; \
	fi
.endfor
	${INSTALL} -d -o root -g mail -m 770 /var/spool/dma

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
