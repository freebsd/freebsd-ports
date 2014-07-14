# Created by: Andrei V. Shetuhin
# $FreeBSD$

PORTNAME=	lemmatizer2
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://reki.ru/products/lemmatizer/ \
		http://havoc.ru/products/lemmatizer/
DISTFILES=	lemmatizer2-2.0.1.tar.gz \
		rus-src-morph.tar.gz  \
		eng-src-morph.tar.gz  \
		ger-src-morph.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Russian / German / English lemmatizer library

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		cmake

DB_DIR?=	/var/db/lemmatizer

DIST_SUBDIR=	${PORTNAME}

USE_LDCONFIG=	${PREFIX}/lib/lemmatizer2

NO_STAGE=	yes
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
	@cd ${WRKSRC} && RML=${WRKSRC};export RML && ./GenerateMorph.sh Russian
	@cd ${WRKSRC} && RML=${WRKSRC};export RML && ./GenerateMorph.sh English
	@cd ${WRKSRC} && RML=${WRKSRC};export RML && ./GenerateMorph.sh German

installmorph:
	@${MKDIR} ${DB_DIR} && ${MKDIR} ${DB_DIR}/Bin \
	&& cd ${WRKSRC} && ${CP} ./Bin/rml.ini ${DB_DIR}/Bin \
	&& ${CP} -r Dicts ${DB_DIR}

.include <bsd.port.mk>
