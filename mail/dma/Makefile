# New ports collection makefile for:	dma
# Date created:				2009-01-17
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	dma
PORTVERSION=	20090825
CATEGORIES=	mail ipv6
MASTER_SITES=	http://mirror.roe.ch/dist/dma/

MAINTAINER=	daniel@roe.ch
COMMENT=	DragonFly Mail Agent, a small MTA for local/outbound mail

USE_BZIP2=	yes
USE_OPENSSL=	yes

MAN8=		dma.8

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dma,${PREFIX}/etc/dma,g' \
		${WRKSRC}/libexec/dma/dma.8 \
		${WRKSRC}/libexec/dma/dma.h
	@${REINPLACE_CMD} -e 's, /etc/dma, ${PREFIX}/etc/dma,g' \
		${WRKSRC}/etc/dma/dma.conf
	@${REINPLACE_CMD} -e '/^WARNS/d' ${WRKSRC}/libexec/dma/Makefile

do-install:
	${INSTALL} -o root -g mail -m 2555 ${WRKSRC}/libexec/dma/dma ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${FILESDIR}/dma.rb ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/libexec/dma/dma.8 ${PREFIX}/man/man8/
	${MKDIR} ${PREFIX}/etc/dma
.for i in dma.conf virtusertable
	${INSTALL_DATA} -m 0644 ${WRKSRC}/etc/dma/${i} ${PREFIX}/etc/dma/${i}.sample
.endfor
	${INSTALL} -o root -g mail -m 0640 ${WRKSRC}/etc/dma/auth.conf \
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
