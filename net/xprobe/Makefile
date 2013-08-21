# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xprobe2
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	SF/xprobe/${PORTNAME}/Xprobe2%20${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ICMP active OS fingerprint scanner

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL=${INSTALL}

MAN1=		xprobe2.1

post-install:	.SILENT
	if [ ! -f ${ETCDIR}/${PORTNAME}.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/${PORTNAME}.conf.sample \
			${ETCDIR}/${PORTNAME}.conf; \
	fi

.include <bsd.port.mk>
