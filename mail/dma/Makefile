# Created by: Daniel Roethlisberger <daniel@roe.ch>

PORTNAME=	dma
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.20210614
PORTEPOCH=	1
CATEGORIES=	mail

MAINTAINER=	garga@FreeBSD.org
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD3CLAUSE

USES=		ssl uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	corecode
GH_TAGNAME=	430f3b59074d6303ce3eb4d9fcf16dcf3538ba31
USE_RC_SUBR=	dma_flushq

MAKE_ENV=	__MAKE_CONF=/dev/null \
		MANDIR=${PREFIX}/share/man/man \
		MK_WERROR=no \
		SRCCONF=/dev/null

CFLAGS+=	-DCONF_PATH='\"${PREFIX}/etc/dma\"' -DDMA_GROUP='\"mail\"' \
		-DDMA_ROOT_USER='\"mailnull\"' -I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PORTSCOUT=	limit:^[0-9\.]*$$
SUB_FILES=	pkg-message

BUILD_WRKSRC=	${WRKSRC}/bsd
INSTALL_WRKSRC=	${WRKSRC}/bsd

# 11.x has dma imported into base and /var/spool/dma added to mtree
PLIST_SUB+=	VARDIR="@comment "

# Allow subports to extend.
CONFFILES+=	auth.conf dma.conf

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf
	@${REINPLACE_CMD} -e '/^MK_MAN/d' \
		-e 's/^NOMAN.*/MAN=/' \
		${WRKSRC}/bsd/dma-mbox-create/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/spool/dma
	${INSTALL_DATA} ${WRKSRC}/dma.conf \
		${STAGEDIR}${ETCDIR}/dma.conf.sample
	${INSTALL_DATA} ${WRKSRC}/auth.conf \
		${STAGEDIR}${ETCDIR}/auth.conf.sample

.include <bsd.port.mk>
