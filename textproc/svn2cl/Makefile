# New ports collection makefile for:    svn2cl
# Date created:                         20 December 2006
# Whom:                                 Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	svn2cl
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://arthurdejong.org/svn2cl/ \
		LOCAL/avl

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Subversion ChangeLog generator

RUN_DEPENDS=	${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion

NO_BUILD=	yes
MAN1=		${PORTNAME}.1
PORTDOCS=	ChangeLog NEWS README TODO
DATAFILES=	authors.xml svn2cl.xsl svn2html.css svn2html.xsl

post-patch:
	@${REINPLACE_CMD} -e 's|XSL="$$dir|XSL="${DATADIR}|' ${WRKSRC}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
.for i in ${DATAFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
