# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	dma
PORTVERSION=	0.12
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	mail

MAINTAINER=	garga@FreeBSD.org
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD3CLAUSE

USES=		uidfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	corecode

BUILD_WRKSRC=	${WRKSRC}/bsd
INSTALL_WRKSRC=	${WRKSRC}/bsd
CFLAGS+=	-I${OPENSSLINC} \
		-DCONF_PATH='\"${PREFIX}/etc/dma\"' \
		-DDMA_ROOT_USER='\"mailnull\"' \
		-DDMA_GROUP='\"mail\"'
LDFLAGS+=	-L${OPENSSLLIB}

MAKE_ENV=	__MAKE_CONF=/dev/null SRCCONF=/dev/null NO_WERROR=defined \
		MANDIR=${MANDIRS}/man

USE_RC_SUBR=	dma_flushq
SUB_FILES=	pkg-message

# Allow subports to extend.
CONFFILES+=	dma.conf auth.conf

# 11.x has dma imported into base and /var/spool/dma added to mtree
PLIST_SUB+=	VARDIR="@comment "

PORTSCOUT=	limit:^[0-9\.]*$$

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf
	@${REINPLACE_CMD} -e '/^MK_MAN/d' -e 's/^NOMAN/NO_MAN/' \
		${WRKSRC}/bsd/dma-mbox-create/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/spool/dma
	${INSTALL_DATA} ${WRKSRC}/dma.conf ${STAGEDIR}${ETCDIR}/dma.conf.sample
	${INSTALL_DATA} ${WRKSRC}/auth.conf ${STAGEDIR}${ETCDIR}/auth.conf.sample

.include <bsd.port.mk>
