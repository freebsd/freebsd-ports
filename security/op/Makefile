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
		ftp://ftp.cso.uiuc.edu/pub/security/coast/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/security/cerias/tools/%SUBDIR%/ \
		ftp://ftp.hacktic.nl/pub/security/coast.cs.purdue.edu/%SUBDIR%/ \
		ftp://ftp.nask.pl/pub/mirror/coast.cs.purdue.edu/%SUBDIR%/
MASTER_SITE_SUBDIR=	unix/sysutils/${PORTNAME}

MAINTAINER=	clefevre@citeweb.net

#
# Clobal variables
#

BINMODE=	4555
MAKE_ARGS+=	BASE="${PREFIX}" \
		OPTS='-Dbsdi -DOP_ACCESS=\"${PREFIX}/etc/op.access\"' \
		LIBS='-ll -lcrypt' \
		BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE} \
		MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}
ALL_TARGET=	${PORTNAME}

MAN8=		op.8

PKGDEINSTALL=	${PKGINSTALL}

#
# Local variables
#

RCS_SUBDIR=	RCS

SAMP_DIR=	${PREFIX}/etc
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

CONF_FILE=	op.access
SAMP_FILE=	${CONF_FILE}
SAMP_SUFX=	.sample
DOC_FILES=	README op.paper

CO?=		co

#
# Post-extract
#

post-extract: checkout-files

checkout-files:
	@cd ${WRKSRC} && ${CO} -q ${RCS_SUBDIR}/*

#
# Post-patch
#

post-patch: patch-install patch-conf-file

patch-install:
	@${PERL} -pi.fbsd -e 's/(install)/$$1 -c/ if (!/:/);' \
		${WRKSRC}/Makefile

patch-conf-file:
	@${PERL} -pi.fbsd -e 's/^/#/ if (!/^#|DEFAULT|MAGIC/);' \
		${WRKSRC}/${CONF_FILE}

#
# Post-install
#

post-install: install-samp-files install-conf-file install-doc-files

install-samp-files:
	@${INSTALL_DATA} ${WRKSRC}/${CONF_FILE} \
		${SAMP_DIR}/${SAMP_FILE}${SAMP_SUFX}

install-conf-file:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

install-doc-files:
.if !defined(NOPORTSDOC)
	@${MKDIR} ${DOC_DIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOC_DIR}/${file}
.endfor
.endif

.include <bsd.port.mk>
