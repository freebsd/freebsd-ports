# New ports collection makefile for:	ask
# Date created:				2 November 2005
# Whom:					Marcelo Araujo <araujobsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ask
PORTVERSION=	2.5.3
CATEGORIES=	mail
MASTER_SITES=	SF/a-s-k/${PORTNAME}-beta/${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Anti Spam Killer content filtering

USE_PYTHON=	yes
NO_BUILD=	yes

ASKLIBDIR=	${PREFIX}/lib/${PORTNAME}
BINS=		askfilter asksetup utils/asksenders
MAN1=		askfilter.1 asksenders.1 asksetup.1
SUB_FILES=	pkg-message
PORTDOCS=	*

post-extract:
	@${REINPLACE_CMD} -E \
		-e "s,/usr/share/ask/templates,${EXAMPLESDIR},g" \
		-e "s,/usr/lib/ask,${ASKLIBDIR},g" \
		-e "s,^(#!)/usr/bin/python,\1${PYTHON_CMD}," \
		${BINS:S,^,${WRKSRC}/,} ${WRKSRC}/*.py

do-install:
	${MKDIR} ${ASKLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${ASKLIBDIR}
	${INSTALL_SCRIPT} ${BINS:S,^,${WRKSRC}/,} ${PREFIX}/bin

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/templates/* ${EXAMPLESDIR}

	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/docs/,} ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.[!1]* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
