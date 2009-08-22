# New ports collection makefile for:	openlldp
# Date created:		27 May 2007
# Whom:			Roar Pettersen <roar@uib.no>
#
# $FreeBSD$
#

PORTNAME=	openlldp
DISTVERSION=	0.3alpha
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.3alpha

MAINTAINER=	roar.pettersen@it.uib.no
COMMENT=	Link Layer Discovery Protocol daemon

GNU_CONFIGURE=	yes

USE_RC_SUBR=	lldpd
PLIST_FILES=	sbin/lldpd

MAN8=	lldpd.8

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS =/CFLAGS +=/g' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lldpd ${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/lldpd.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
