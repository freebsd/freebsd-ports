# Ports collection makefile for:  xprobe
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xprobe2
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	SF/xprobe/${PORTNAME}/Xprobe2%20${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	ICMP active OS fingerprint scanner

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL=${INSTALL}
MAKE_JOBS_SAFE=	yes

MAN1=		xprobe2.1

post-install:	.SILENT
	if [ ! -f ${ETCDIR}/${PORTNAME}.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/${PORTNAME}.conf.sample \
			${ETCDIR}/${PORTNAME}.conf; \
	fi

.include <bsd.port.mk>
