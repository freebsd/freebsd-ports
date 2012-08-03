# New ports collection makefile for:	abills
# Date created:		2 February 2005
# Whom:			Michael Lednev <liettneff@bk.ru>
#
# $FreeBSD$
#

PORTNAME=	abills
PORTVERSION=	0.53
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	liettneff@bk.ru
COMMENT=	Billing system for dialup, VPN, and VoIP management

LICENSE=	GPLv2

RUN_DEPENDS=	radiusd:${PORTSDIR}/net/freeradius \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Digest-MD4>=0:${PORTSDIR}/security/p5-Digest-MD4 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES

USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

post-patch:
	@ ${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} {} \;
	@ ${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' -e 's,/usr/abills,${PREFIX}/abills,g' {} \;
	@ ${FIND} ${WRKSRC} -type f -name '*.DS*' -exec ${RM} {} \;

do-install:
	@ ${CP} -R ${WRKSRC} ${PREFIX}
	@ ${CHOWN} -R www ${PREFIX}/abills/cgi-bin

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
