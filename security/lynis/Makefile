# New ports collection makefile for:  Lynis
# Date created:        15 November 2008
# Whom:                Cory McIntire (loon@noncensored.com)
#
# $FreeBSD$
#

PORTNAME=	lynis
PORTVERSION=	1.2.6
CATEGORIES=	security
MASTER_SITES=	http://www.rootkit.nl/files/ \
		http://downloads.rootkit.nl/

MAINTAINER=	loon@noncensored.com
COMMENT=	Security and system auditing tool

NO_BUILD=	yes

PORTDOCS=	*
MAN8=		lynis.8

post-patch:
	@${REINPLACE_CMD} -e '/tINCLUDE_TARGETS/ s|".*"|"${DATADIR}/include"|; \
		/tPLUGIN_TARGETS/ s|".*"|"${DATADIR}/plugins"|; \
		/tDB_TARGETS/ s|".*"|"${DATADIR}/db"|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8
	${MKDIR} ${PREFIX}/etc/lynis
	${INSTALL_DATA} ${WRKSRC}/default.prf ${PREFIX}/etc/lynis
	${MKDIR} ${DATADIR}
.for dir in include db dev plugins
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in CHANGELOG INSTALL FAQ LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
