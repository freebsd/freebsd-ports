# New ports collection makefile for:	lemmatizer
# Date created:				26 May 2005
# Whom:					Andrei V. Shetuhin
#
# $FreeBSD$
#

PORTNAME=	lemmatizer
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://reki.ru/products/lemmatizer/
DISTFILES=	lemmatizer-1.0.tar.gz \
		rus-src-morph.tar.gz  \
		eng-src-morph.tar.gz  \
		ger-src-morph.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Russian / German / English lemmatizer library

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

DB_DIR?=	/var/db/lemmatizer

DIST_SUBDIR=	${PORTNAME}

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-datadir=${DB_DIR}

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      DB_DIR=directory        Set alternate directory for database files"
	@${ECHO} "                              (default is /var/db/lemmatizer)"
	@${ECHO} ""

post-extract:
	@cd ${WRKDIR} && ${CP} -r Dicts ${WRKSRC}

generatemorph:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating dictionaries" \
	&& ${GMAKE} generatemorph

installmorph:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Installing dictionaries" \
	&& ${GMAKE} installmorph

.include <bsd.port.mk>
