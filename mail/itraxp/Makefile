# New ports collection makefile for:    itraxp
# Date created:         Thu Sep 16 16:45:51 UTC 2004
# Whom:                 Andrey Slusar <anrays@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	itraxp
PORTVERSION=	1.03.20050513
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	itraxpl

MAINTAINER=	anrays@gmail.com
COMMENT=	Advanced Perl supporting FTN messages tracker

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/makefiles/Linux

SUBDIRS=	${DOCSDIR} ${DOCSDIR}/misc ${EXAMPLESDIR} \
		${EXAMPLESDIR}/include ${EXAMPLESDIR}/tab ${EXAMPLESDIR}/tpl

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} < 500000
	${CAT} ${PKGMESSAGE}
.endif

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

.include <bsd.port.post.mk>
