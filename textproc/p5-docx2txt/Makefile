# $FreeBSD$

PORTNAME=	docx2txt
PORTVERSION=	1.4
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Utility to convert Docx documents to equivalent Text documents

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes

pre-patch:
		${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/docx2txt.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/docx2txt.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/docx2txt.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docx2txt.config ${STAGEDIR}${PREFIX}/etc/docx2txt.config.sample

.include <bsd.port.mk>
