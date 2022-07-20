PORTNAME=	dma
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.20220128
PORTEPOCH=	1
CATEGORIES=	mail

MAINTAINER=	garga@FreeBSD.org
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD3CLAUSE

USES=		ssl uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	corecode
GH_TAGNAME=	92937587bbfeab53653b841afe76af2fa6dad345
USE_RC_SUBR=	dma_flushq

MAKE_ENV=	__MAKE_CONF=/dev/null \
		MANDIR=${PREFIX}/share/man/man \
		MK_WERROR=no \
		SRCCONF=/dev/null

CFLAGS+=	-DCONF_PATH='\"${PREFIX}/etc/dma\"' -DDMA_GROUP='\"mail\"' \
		-DDMA_ROOT_USER='\"mailnull\"' -I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PORTSCOUT=	limit:^[0-9\.]*$$
SUB_FILES=	dma_cron pkg-message

BUILD_WRKSRC=	${WRKSRC}/bsd
INSTALL_WRKSRC=	${WRKSRC}/bsd

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf
	@${REINPLACE_CMD} -e '/^MK_MAN/d' \
		-e 's/^NOMAN.*/MAN=/' \
		${WRKSRC}/bsd/dma-mbox-create/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/spool/dma
	${INSTALL_DATA} ${WRKSRC}/dma.conf \
		${STAGEDIR}${ETCDIR}/dma.conf.sample
	${INSTALL_DATA} ${WRKSRC}/auth.conf \
		${STAGEDIR}${ETCDIR}/auth.conf.sample
	${INSTALL_DATA} ${WRKDIR}/dma_cron \
		${STAGEDIR}${PREFIX}/etc/cron.d/dma

.include <bsd.port.mk>
