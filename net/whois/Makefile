# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	whois
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.7
CATEGORIES=	net

MAINTAINER=	coco@executive-computing.de
COMMENT=	Marco d'Itri whois client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libidn2.so:dns/libidn2

USES=		iconv gmake perl5 pkgconfig
USE_PERL5=	build
MAKE_ARGS=	BASEDIR="${STAGEDIR}"

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

USE_GITHUB=	yes
GH_ACCOUNT=	rfc1036

post-patch:
	@${REINPLACE_CMD} -e "s|%%MWHOISCONF%%|${PREFIX}/etc/mwhois.conf|g" ${WRKSRC}/whois.1
	@${REINPLACE_CMD} -e "s|%%MWHOIS%%|mwhois|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|%%MWHOIS%%|mwhois|g" ${WRKSRC}/po/Makefile
	@${REINPLACE_CMD} -e "s|%%MWHOIS%%|mwhois|g" ${WRKSRC}/whois.1
	@${REINPLACE_CMD} -e "s|%%MWHOIST%%|MWHOIS|g" ${WRKSRC}/whois.1
	@${REINPLACE_CMD} -e "s|%%MWHOIST%%|MWHOIS|g" ${WRKSRC}/whois.conf.5
	@${REINPLACE_CMD} -e "s|%%MWHOIS%%|mwhois|g" ${WRKSRC}/whois.conf.5
	@${REINPLACE_CMD} -e "s|%%MWHOISCONF%%|${PREFIX}/etc/mwhois.conf|g" ${WRKSRC}/whois.conf.5
	@${REINPLACE_CMD} -e "s|%%MWHOISCONF%%|${PREFIX}/etc/mwhois.conf|g" ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/config.h

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "s| pos||" -e "s| install-pos||" \
			-e "s|-lintl||" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|# define ENABLE_NLS||" ${WRKSRC}/config.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mwhois
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mkpasswd

.include <bsd.port.mk>
