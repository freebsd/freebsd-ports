# Created by: gahr
# $FreeBSD$

PORTNAME=	ez-pine-gpg
DISTVERSION=	0.4h
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://business-php.com/opensource/ez-pine-gpg/
DISTNAME=	${PORTNAME}_v${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Set of scripts to use gpg with Pine

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

WRKSRC=	${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC} && ./install ${STAGEDIR}${PREFIX}/bin)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
