# New ports collection makefile for:	tkxmlive
# Date created:				4 December 2003
# Whom:					nivit@users.sourceforge.net
#
# $FreeBSD$

PORTNAME=		tkxmlive
PORTVERSION=		0.1.5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		tkxmlive-0.1.5-1

MAINTAINER=		nivit@users.sourceforge.net
COMMENT=		Tcl/Tk XML Intelligence Visual Editor

RUN_DEPENDS+=		wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
			${LOCALBASE}/lib/bwidget/pkgIndex.tcl:${PORTSDIR}/x11-toolkits/bwidget

NO_BUILD=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

TK_VER?=		8.4
WISH=			wish${TK_VER}

REPLACE_FILES=		${WRKSRC}/interface.tcl \
			${WRKSRC}/tkxmlive

post-patch: .SILENT
	for FILE in ${REPLACE_FILES}; do \
		${SED} -i .bak\
		-e "/%%DATADIR%%/s//${DATADIR:S/\//\\\//g}/g" \
		-e "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/g" \
		-e "/%%WISH%%/s//${WISH:S/\//\\\//g}/g" \
		$${FILE}; \
	done;

LN_OPTS?=		-sf

FIND_ARGS1=		-type d \! -empty
FIND_ARGS2=		-type f -and -perm -a+x -and \! \
			-name "*.orig" \! -name "*.bak"
FIND_ARGS3=		-type f -and \! -perm -a+x -and \! \
			-name "*.orig" \! -name "*~" \! \
			-regex ".*[[:upper:]]+"

do-install: .SILENT
# Script and data
	cd ${WRKSRC}; \
	DIRS=$$(${FIND} . ${FIND_ARGS1}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${DATADIR}/$${DIR}; \
	done; \
	FILES=$$(${FIND} . ${FIND_ARGS2}); \
	for FILE in $${FILES}; do \
		${INSTALL_SCRIPT} $${FILE} ${DATADIR}/$${FILE}; \
	done; \
	FILES=$$(${FIND} -E . ${FIND_ARGS3}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${DATADIR}/$${FILE}; \
	done;

# Links to executables
	cd ${WRKSRC}; \
	FILES=${PORTNAME}; \
	for f in $${FILES}; do \
		${LN} ${LN_OPTS} ${DATADIR}/$${f} ${PREFIX}/bin/$${f}; \
	done;

.include <bsd.port.post.mk>
