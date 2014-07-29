# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	whois
PORTVERSION=	5.0.23
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lapo@lapo.it
COMMENT=	Marco d'Itri whois client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable

USES=		iconv gmake perl5 tar:xz
USE_PERL5=	build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS=	BASEDIR="${STAGEDIR}"

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e "s| pos||" -e "s| install-pos||" \
			-e "s|-lintl||" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|# define ENABLE_NLS||" ${WRKSRC}/config.h
.endif

.include <bsd.port.mk>
