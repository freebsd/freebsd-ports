# New ports collection makefile for:	dma
# Date created:				2009-01-17
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#
# Based on a tarball from https://github.com/corecode/dma/tarball/<version>
# rather than from Dragonfly.
#

PORTNAME=		dma
PORTVERSION=		v0.7
PORTREVISION=		1
PORTEPOCH=		1
CATEGORIES=		mail ipv6
#MASTER_SITES=		https://github.com/		# 302 temp move
MASTER_SITES=		https://nodeload.github.com/${GITHUB_USER}/${PORTNAME}/tarball/
DISTNAME=		${PORTVERSION}
EXTRACT_SUFX=
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITHUB_HASH}

USE_OPENSSL=	yes

MAN8=		dma.8

GITHUB_HASH=		db9a42b
GITHUB_USER=		corecode

CFLAGS+=	-I${OPENSSLINC} \
		-DCONF_PATH='\"${PREFIX}/etc/dma\"' \
		-DDMA_ROOT_USER='\"mailnull\"' \
		-DDMA_GROUP='\"mail\"'
LDFLAGS+=	-L${OPENSSLLIB}

USE_RC_SUBR=	dma_flushq
SUB_FILES=	pkg-message

# Allow subports to extend.
CONFFILES+=	dma.conf auth.conf

.include <bsd.port.pre.mk>

pre-patch:
	@${MKDIR} ${WRKSRC}/dma ${WRKSRC}/dma-mbox-create
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf

do-install:
	${INSTALL} -o root -g mail -m 2555 ${WRKSRC}/dma/dma ${PREFIX}/libexec
	${INSTALL} -o root -g mail -m 4550 \
		${WRKSRC}/dma-mbox-create/dma-mbox-create ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/dma.8 ${PREFIX}/man/man8/
	${MKDIR} ${PREFIX}/etc/dma
.for i in ${CONFFILES}
	${INSTALL_DATA} -m 0644 ${WRKSRC}/${i} ${PREFIX}/etc/dma/${i}.sample
.endfor
	${CHMOD} o-r ${PREFIX}/etc/dma/auth.conf.sample
.for i in ${CONFFILES}
	if [ ! -f ${PREFIX}/etc/dma/${i} ]; then \
		${CP} -p ${PREFIX}/etc/dma/${i}.sample \
			${PREFIX}/etc/dma/${i} ; \
	fi
.endfor
	${INSTALL} -d -o root -g mail -m 770 /var/spool/dma

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
