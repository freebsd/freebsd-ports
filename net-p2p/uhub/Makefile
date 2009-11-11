# New ports collection makefile for:	uhub
# Date created:		16 Oct 2009
# Whom:			Yashin Dmitry <yashin.dm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uhub
PORTVERSION=	0.2.8
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.extatic.org/downloads/uhub/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	yashin.dm@gmail.com
COMMENT=	High performance peer-to-peer hub for the ADC network

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USE_PERL5=	yes
USE_GMAKE=	yes

USE_RC_SUBR=	uhub.sh

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	${WRKSRC}/GNUmakefile

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/uhub/|${PREFIX}&|' ${WRKSRC}/doc/uhub.conf

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/uhub.conf ${PREFIX}/etc/uhub/uhub.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/users.conf ${PREFIX}/etc/uhub/users.conf.sample
	@if [ -f ${PREFIX}/etc/uhub/motd.txt ]; then \
		${TOUCH} ${PREFIX}/etc/uhub/motd.txt.sample ; \
	fi

.include <bsd.port.mk>
