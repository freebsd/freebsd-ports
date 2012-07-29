# New ports collection makefile for:	jspacker
# Date created:		2009-07-04
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jspacker
DISTVERSION=	1.00b
CATEGORIES=	www
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/ \
		http://deanedwards.googlecode.com/svn/trunk/download/
DISTNAME=	packer2.perl

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	JavaScript compressor/obfuscator (Perl version)

JSPACKER=	jsPacker.pl

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_PERL5_RUN=	yes
USE_ZIP=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	JSPACKER=${JSPACKER} \
		PERL5=${PERL5}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR} && \
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.pm ${DATADIR} && \
	${INSTALL_SCRIPT} ${JSPACKER} ${DATADIR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && \
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.htm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
