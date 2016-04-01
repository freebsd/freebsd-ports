# Created by: Joe Barbish <fbsd_user@a1poweruser.com>
# $FreeBSD$

PORTNAME=	ipfilter2dshield
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.dshield.org/clients/
DISTNAME=	dshield-freebsd.pl
EXTRACT_SUFX=	.txt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Official DShield client for ipfilter firewall logs

RUN_DEPENDS=	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask

USES=		perl5 shebangfix
SHEBANG_FILES=	${DISTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${DISTNAME}

pre-install:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%DISTNAME%%=${DISTNAME}=g" \
		pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${ETCDIR}/${DISTNAME}.sample
	${INSTALL} -m 760 ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
