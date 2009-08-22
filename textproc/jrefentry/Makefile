# New ports collection makefile for:   jrefentry
# Date created:                1 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jrefentry
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DocBook XML JRefEntry DTD

RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbook.cat:${PORTSDIR}/textproc/docbook-xml

NO_BUILD=	yes

XMLDIR=		${PREFIX}/share/xml/docbook/${PORTNAME}

do-install:
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/jrefentry.dtd ${XMLDIR}
	${ECHO_CMD} 'PUBLIC "-//Norman Walsh//DTD JRefEntry V1.1//EN" "jrefentry.dtd"' \
		>${XMLDIR}/catalog

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/jtest.xml ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}

.include <bsd.port.mk>
