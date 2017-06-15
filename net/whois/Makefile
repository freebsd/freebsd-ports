# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	whois
PORTVERSION=	5.1.5
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	coco@executive-computing.de
COMMENT=	Marco d'Itri whois client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv gmake perl5
USE_PERL5=	build
MAKE_ARGS=	BASEDIR="${STAGEDIR}"

OPTIONS_DEFINE=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

USE_GITHUB=	yes
GH_ACCOUNT=	rfc1036
GH_TAGNAME=	d346ca6

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%MWHOISCONF%%|${PREFIX}/etc/mwhois.conf|g" ${WRKSRC}/whois.1
	@${REINPLACE_CMD} -e "s|%%MWHOIS%%|mwhois|g" ${WRKSRC}/whois.1
	@${REINPLACE_CMD} -e "s|%%MWHOIST%%|MWHOIS|g" ${WRKSRC}/whois.1
	@${REINPLACE_CMD} -e "s|%%MWHOIST%%|MWHOIS|g" ${WRKSRC}/whois.conf.5
	@${REINPLACE_CMD} -e "s|%%MWHOIS%%|mwhois|g" ${WRKSRC}/whois.conf.5
	@${REINPLACE_CMD} -e "s|%%MWHOISCONF%%|${PREFIX}/etc/mwhois.conf|g" ${WRKSRC}/whois.conf.5
	@${REINPLACE_CMD} -e "s|%%MWHOISCONF%%|${PREFIX}/etc/mwhois.conf|g" ${WRKSRC}/config.h
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e "s| pos||" -e "s| install-pos||" \
			-e "s|-lintl||" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|# define ENABLE_NLS||" ${WRKSRC}/config.h
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mwhois
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mkpasswd

.include <bsd.port.mk>
