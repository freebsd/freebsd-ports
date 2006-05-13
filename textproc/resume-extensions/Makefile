# New ports collection makefile for:	resume-extensions
# Date created:                		August 03 2004
# Whom:                        		Aaron Straup Cope
# $FreeBSD$

PORTNAME=	resume-extensions
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	http://aaronland.info/xsl/xmlresume/
DISTNAME=	xml${PORTNAME}-${PORTVERSION}

MAINTAINER=	ascope@cpan.org
COMMENT=	Extends the XML Resume library

RUN_DEPENDS=	${LOCALBASE}/share/xsl/resume:${PORTSDIR}/textproc/resume \
		${LOCALBASE}/share/xsl/string/print-n-times.xsl:${PORTSDIR}/textproc/print-n-times \
		${LOCALBASE}/share/xsl/xhtml/add-css-links.xsl:${PORTSDIR}/textproc/add-css-links

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/share|${LOCALBASE}/share|' \
		${WRKSRC}/lib/extrefs.xsl
	${REINPLACE_CMD} -e 's|/usr/local/share|${LOCALBASE}/share|' \
		${WRKSRC}/format/html.xsl
	${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${ECHO} "Installing in ${PREFIX}/share/xsl/${PORTNAME}"
	@${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/share/xsl/${PORTNAME}

.include <bsd.port.mk>
