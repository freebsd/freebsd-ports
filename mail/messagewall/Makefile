# New ports collection makefile for:	messagewall-1.0.6
# Date created: 	24 Sep 2002
# Whom:			Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	messagewall
PORTVERSION=	1.0.6
CATEGORIES=	mail
MASTER_SITES=	http://www.messagewall.org/download/
DISTNAME=	messagewall-${PORTVERSION}

MAINTAINER=	opr@bsdaemon.be

BUILD_DEPENDS=  ${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring \
		${LOCALBASE}/include/firedns.h:${PORTSDIR}/net/firedns

MAN1=		messagewall.1 messagewallctl.1 messagewallstats.1
MAN5=		messagewall.conf.5 messagewall_profiles.5
CONF1=		messagewall.conf

WRKSRC=         ${WRKDIR}/messagewall
GNU_CONFIGURE=  yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/firemake.cflags \
		${WRKSRC}/firemake.ldflags

do-install:
	@${CP} ${WRKSRC}/messagewall ${PREFIX}/bin
	@${CP} ${WRKSRC}/messagewallctl ${PREFIX}/bin
	@${CP} ${WRKSRC}/messagewallstats ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/messagewall
	@${CP} ${WRKSRC}/virus.patterns ${PREFIX}/etc/messagewall/
	@${CP} -r ${WRKSRC}/profiles ${PREFIX}/etc/messagewall/
.for file in ${CONF1}
	@${CP} ${WRKSRC}/conf/${file} ${PREFIX}/etc/${file}.sample
.endfor
.for file in ${MAN1}
	@${CP} ${WRKSRC}/man/${file} ${PREFIX}/man/man1/
.endfor
.for file in ${MAN5}
	@${CP} ${WRKSRC}/man/${file} ${PREFIX}/man/man5/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
