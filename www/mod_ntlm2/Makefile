# Created by: Alex "lissyara" Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	mod_ntlm2
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/modntlm/modntlm2/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NTLM authentication module for the Apache2 webserver

BUILD_DEPENDS=	smbclient:${SAMBA_PORT}

SAMBA_PORT?=	net/samba36


USE_APACHE=	22
MAKE_ENV=	APXS=${APXS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${APXS} -i -n 'ntlm' -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} ${WRKSRC}/mod_ntlm.la
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_ntlm.so

.include <bsd.port.mk>
