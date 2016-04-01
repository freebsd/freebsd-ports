# Created by: Michael Lednev <liettneff@bk.ru>
# $FreeBSD$

PORTNAME=	abills
PORTVERSION=	0.59
CATEGORIES=	net
MASTER_SITES=	SF
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Billing system for dialup, VPN, and VoIP management

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	radiusd:net/freeradius2 \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Digest-MD4>=0:security/p5-Digest-MD4 \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Crypt-DES>=0:security/p5-Crypt-DES

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

USES=		perl5 tar:tgz
USE_PERL5=	run

PLIST_SUB=	WWWOWN="${WWWOWN}"
SUB_FILES=	pkg-message

post-patch:
	@${GREP} -lR "/usr/abills" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/abills|${PREFIX}/abills|g'
	@${GREP} -lR "/usr/bin/perl" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/bin/perl|${PERL}|g'

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/abills
	@(${TAR} -C ${WRKSRC} --exclude "*.DS*" --exclude "*.bak" \
		--exclude "*.orig" -cf - . | ${TAR} -C ${STAGEDIR}${PREFIX}/abills \
		--unlink -xf -)
	@${FIND} ${STAGEDIR}${PREFIX}/abills -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${STAGEDIR}${PREFIX}/abills -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
