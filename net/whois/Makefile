# New ports collection makefile for:   whois
# Date created:                02 Oct 2003
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	whois
PORTVERSION=	4.6.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.linux.it/~md/software/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	filippo@widestore.net
COMMENT=	Marco d'Itri whois client

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

MAN1=	whois.1

USE_GETTEXT=	yes
USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s|prefix\=/usr/local|prefix\=${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g" ${WRKSRC}/po/Makefile

.include <bsd.port.mk>
