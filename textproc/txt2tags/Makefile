# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	txt2tags
# Date created:		2002-12-20
# Whom:			Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	txt2tags
PORTVERSION=	1.3
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	textproc
MASTER_SITES=	http://txt2tags.sourceforge.net/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alane@freebsd.org

NO_BUILD=	yes
USE_PYTHON=	yes
PLIST=		${WRKDIR}/plist
PREFIX=		${LOCALBASE}

.include <bsd.port.pre.mk>

DOCS_SUBDIR=		${DOCSDIR:S|^${PREFIX}/||}
EXAMPLES_SUBDIR=	${EXAMPLESDIR:S|^${PREFIX}/||}

BIN_SUBDIR=		bin
BINDIR=			${PREFIX}/${BIN_SUBDIR}
DATA_SUBDIR=		share
DATADIR=		${PREFIX}/${DATA_SUBDIR}
ETC_SUBDIR=		etc
ETCDIR=			${PREFIX}/${ETC_SUBDIR}
LIB_SUBDIR=		lib
LIBDIR=			${PREFIX}/${LIB_SUBDIR}
PKGDATA_SUBDIR=		share/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PKGDATADIR=		${PREFIX}/${PKGDATA_SUBDIR}
PKGETC_SUBDIR=		etc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PKGETCDIR=		${PREFIX}/${PKGETC_SUBDIR}
PKGLIB_SUBDIR=		lib/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PKGLIBDIR=		${PREFIX}/${PKGLIB_SUBDIR}

post-patch:
	>${PLIST}

ADD2PLIST=		${ECHO_CMD} >>${PLIST}

do-install:
	${MKDIR} ${BINDIR}
	cd ${WRKSRC};\
	${INSTALL_SCRIPT} txt2tags ${BINDIR};\
	${ADD2PLIST} ${BIN_SUBDIR}/txt2tags
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/userguide
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/contrib
	${MKDIR} ${EXAMPLESDIR}/extras
	${MKDIR} ${EXAMPLESDIR}/samples
	cd ${WRKSRC};\
	for i in ChangeLog.txt README.txt README.html RULES; do\
		${INSTALL_DATA} $$i ${DOCSDIR};\
		${ADD2PLIST} ${DOCS_SUBDIR}/$$i;\
	done
	cd ${WRKSRC};\
	${INSTALL_DATA} userguide/* ${DOCSDIR}/userguide;\
	for i in userguide/*; do\
		${ADD2PLIST} ${DOCS_SUBDIR}/userguide/$$(basename $$i);\
	done
.for dir in contrib extras samples
	cd ${WRKSRC};\
	${INSTALL_DATA} ${dir}/* ${EXAMPLESDIR}/${dir};\
	for i in ${dir}/*; do\
		${ADD2PLIST} ${EXAMPLES_SUBDIR}/${dir}/$$(basename $$i);\
	done
.endfor
	${ADD2PLIST} "@dirrm" ${EXAMPLES_SUBDIR}/samples
	${ADD2PLIST} "@dirrm" ${EXAMPLES_SUBDIR}/extras
	${ADD2PLIST} "@dirrm" ${EXAMPLES_SUBDIR}/contrib
	${ADD2PLIST} "@dirrm" ${EXAMPLES_SUBDIR}
	${ADD2PLIST} "@dirrm" ${DOCS_SUBDIR}/userguide
	${ADD2PLIST} "@dirrm" ${DOCS_SUBDIR}
.endif # !defined(NOPORTDOCS)

.include <bsd.port.post.mk>

#EOF
