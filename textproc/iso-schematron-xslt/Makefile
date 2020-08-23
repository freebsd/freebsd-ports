# $FreeBSD$

PORTNAME=	iso-schematron-xslt
PORTVERSION=	20130313
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.schematron.com/tmp/ \
		LOCAL/sunpoet
DISTFILES=	iso-schematron-xslt1.zip \
		iso-schematron-xslt2.zip

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The Leading Implementation of ISO Schematron

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}/xslt1 ${WRKSRC}/xslt2
	@${EXTRACT_CMD} -d ${WRKSRC}/xslt1 -q ${DISTDIR}/iso-schematron-xslt1.zip
	@${EXTRACT_CMD} -d ${WRKSRC}/xslt2 -q ${DISTDIR}/iso-schematron-xslt2.zip

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/xsl/iso-schematron

.include <bsd.port.mk>
