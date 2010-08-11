# New ports collection makefile for:	dma
# Date created:				2009-01-17
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	dma
PORTVERSION=	20091004
CATEGORIES=	mail ipv6
MASTER_SITES=	http://people.FreeBSD.org/~bapt/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

LICENSE=	BSD

USE_OPENSSL=	yes

MAN8=		dma.8

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.8 \
		${WRKSRC}/dma.h
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/dma.conf

do-install:
	${INSTALL} -o root -g mail -m 2555 ${WRKSRC}/dma ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/dma.8 ${PREFIX}/man/man8/
	${MKDIR} ${PREFIX}/etc/dma
.for i in dma.conf virtusertable
	${INSTALL_DATA} -m 0644 ${WRKSRC}/${i} ${PREFIX}/etc/dma/${i}.sample
.endfor
	${INSTALL} -o root -g mail -m 0640 ${WRKSRC}/auth.conf \
		${PREFIX}/etc/dma/auth.conf.sample
.for i in dma.conf virtusertable auth.conf
	if [ ! -f ${PREFIX}/etc/dma/${i} ]; then \
		${CP} -p ${PREFIX}/etc/dma/${i}.sample \
			${PREFIX}/etc/dma/${i} ; \
	fi
.endfor
	${INSTALL} -d -o root -g mail -m 770 /var/spool/dma

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
