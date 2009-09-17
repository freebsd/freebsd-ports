# New ports collection makefile for:	abills
# Date created:		2 February 2005
# Whom:			Michael Lednev <liettneff@bk.ru>
#
# $FreeBSD$
#

PORTNAME=	abills
PORTVERSION=	0.41
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	liettneff@bk.ru
COMMENT=	Billing system for dialup, VPN and VoIP management

RUN_DEPENDS=	radiusd:${PORTSDIR}/net/freeradius \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD4.pm:${PORTSDIR}/security/p5-Digest-MD4 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES

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
