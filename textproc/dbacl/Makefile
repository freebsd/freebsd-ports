# New ports collection makefile for:	dbacl
# Date created:		2003-10-30
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	dbacl
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@dragon2.net
COMMENT=	Digramic Bayesian classifier

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PROGRAMS=	bayesol dbacl mailinspect
SCRIPTS=	mailcross
MAN1=		bayesol.1 dbacl.1 mailcross.1 mailinspect.1
DOCS=		AUTHORS ChangeLog README dbacl.ps email.html tutorial.html
EXAMPLES=	sample*.txt japanese.txt example*.risk toy.risk prop.pl

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1 && \
		${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
