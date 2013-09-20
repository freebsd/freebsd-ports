# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	whois
PORTVERSION=	5.0.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lapo@lapo.it
COMMENT=	Marco d'Itri whois client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv gmake perl5
USE_PERL5=	build

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ARGS=	OPTS=""

MAN1=		mwhois.1 mkpasswd.1

PLIST_FILES=	bin/mwhois bin/mkpasswd

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g" ${WRKSRC}/po/Makefile

.include <bsd.port.mk>
