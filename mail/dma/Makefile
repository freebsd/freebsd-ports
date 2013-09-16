# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$
#
# Based on a tarball from https://github.com/corecode/dma/tarball/<version>
# rather than from Dragonfly.

PORTNAME=		dma
PORTVERSION=		v0.9
PORTEPOCH=		1
CATEGORIES=		mail ipv6
EXTRACT_SUFX=

MAINTAINER=	bzeeb+freebsdports@zabbadoz.net
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD

USE_OPENSSL=	yes

MAN8=		dma.8

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
IGNORE=	Does not build in 8.x
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
