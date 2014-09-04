# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	dma
PORTVERSION=	v0.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail ipv6
EXTRACT_SUFX=

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD3CLAUSE

USE_OPENSSL=	yes

USE_GITHUB=	yes
GH_COMMIT=	2bb8bcb
GH_ACCOUNT=	corecode
GH_TAGNAME=	${GH_COMMIT}

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

.if ${OSVERSION} < 900000
EXTRA_PATCHES=	${.CURDIR:H:H}/mail/dma/files/extrapatch-8-spool.c
.else
EXTRA_PATCHES=  ${.CURDIR:H:H}/mail/dma/files/extrapatch-else-spool.c
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}/dma ${WRKSRC}/dma-mbox-create
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf
.if ${OSVERSION} < 1000013
	@${REINPLACE_CMD} -e 's,^YFLAGS.*,,' ${WRKSRC}/dma/Makefile
.endif

do-install:
	${INSTALL_PROGRAM}  ${WRKSRC}/dma/dma ${STAGEDIR}/${PREFIX}/libexec
	${INSTALL_PROGRAM} \
		${WRKSRC}/dma-mbox-create/dma-mbox-create ${STAGEDIR}/${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/dma.8 ${STAGEDIR}/${PREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/dma
.for i in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${PREFIX}/etc/dma/${i}.sample
.endfor
	${MKDIR} ${STAGEDIR}/var/spool/dma

.include <bsd.port.post.mk>
