# New ports collection makefile for:    itraxp
# Date created:         Thu Sep 16 16:45:51 UTC 2004
# Whom:                 Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	itraxp
PORTVERSION=	1.03.20050513
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}l/${PORTNAME}%201.03/Itraxp%201.03%2020050513

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Advanced Perl supporting FTN messages tracker

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/makefiles/Linux

SUBDIRS=	${DOCSDIR} ${DOCSDIR}/misc ${EXAMPLESDIR} \
		${EXAMPLESDIR}/include ${EXAMPLESDIR}/tab ${EXAMPLESDIR}/tpl

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${SUBDIRS}
	${INSTALL_DATA} ${WRKSRC}/../../doc/itraxp.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../../doc/misc/st_itraxp.pl ${DOCSDIR}/misc
.for i in itraxp.cfg procin.pl procmain.pl procout.pl readme
	${INSTALL_DATA} ${WRKSRC}/../../doc/example.cfg/${i} ${EXAMPLESDIR}
.endfor
	${CP} ${WRKSRC}/../../doc/example.cfg/include/*.cfg ${EXAMPLESDIR}/include
	${CP} ${WRKSRC}/../../doc/example.cfg/tab/*.tbl ${EXAMPLESDIR}/tab
	${CP} ${WRKSRC}/../../doc/example.cfg/tpl/*.tpl ${EXAMPLESDIR}/tpl
.endif

.include <bsd.port.mk>
