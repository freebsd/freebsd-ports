# New ports collection makefile for:    op
# Date created:         Monday 29 January 2001
# Whom:                 Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	op
PORTVERSION=	1.11
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cerias.purdue.edu/pub/tools/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/security/cerias/tools/%SUBDIR%/ \
	ftp://ftp.hacktic.nl/pub/security/coast.cs.purdue.edu/%SUBDIR%/ \
		ftp://ftp.nask.pl/pub/mirror/coast.cs.purdue.edu/%SUBDIR%/
MASTER_SITE_SUBDIR=	unix/sysutils/${PORTNAME}

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

BINMODE=	4555
MAKE_ARGS=	BASE="${PREFIX}" \
		OPTS='-Dbsdi -DOP_ACCESS=\"${CONF_DIR}/${CONF_FILE}\"' \
		LIBS='-ll -lcrypt' \
		BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE} \
		MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}
ALL_TARGET=	${PORTNAME}

MAN8=		op.8

PKGDEINSTALL=	${PKGINSTALL}

# Local variables
#

CO?=		co

RCS_SUBDIR=	RCS
CONF_DIR=	${PREFIX}/etc

CONF_FILE=	op.access
SAMP_SUFX=	.sample
DOC_FILES=	README op.paper

# Post-extract
#

post-extract: checkout-files

checkout-files:
	@cd ${WRKSRC} && ${CO} -q ${RCS_SUBDIR}/*

# Post-patch
#

post-patch: patch-makefile patch-conf-file

patch-makefile:
	@${PERL} -pi.fbsd -e 's|(install)|$$1 -c| if (!/:/);' \
		${WRKSRC}/Makefile

patch-conf-file:
	@${PERL} -pi.fbsd -e 's|^|#| if (!/^#|DEFAULT|MAGIC/);s|/usr/ucb:||;' \
		${WRKSRC}/${CONF_FILE}

# Post-install
#

post-install: install-samp-files install-conf-file install-doc-files

install-samp-files:
	@${INSTALL_DATA} ${WRKSRC}/${CONF_FILE} \
		${CONF_DIR}/${CONF_FILE}${SAMP_SUFX}

install-conf-file:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

install-doc-files:
.if !defined(NOPORTSDOC)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/${file}
.endfor
.endif

.include <bsd.port.mk>
