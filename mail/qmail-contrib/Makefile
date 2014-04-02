# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	qmail-contrib
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTFILES=	dot-forward-${DF_VER}.tar.gz \
		fastforward-${FF_VER}.tar.gz

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Contributed programs for qmail

OPTIONS_DEFINE=	DOCS

USES=		qmail:run

ALL_TARGET=	prog
INSTALL_TARGET=	setup

PREFIX?=	${QMAIL_PREFIX}
NO_PREFIX_RMDIR=yes

FF_VER=		0.51
DF_VER=		0.71
QCK_VER=	0.1

# XXX: This port should be split into sub-packages/ports
WRKFF=		${WRKDIR}/fastforward-${FF_VER}
WRKDF=		${WRKDIR}/dot-forward-${DF_VER}

NO_MTREE=	yes

PORTDOCS=	ALIASES
DOCSDIR=	doc/${PORTNAME}

.include <bsd.port.pre.mk>

pre-patch:
	@${PATCH} -d ${WRKFF} -s <${PATCHDIR}/extra-patch-newaliases

post-patch:
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKFF}/conf-qmail
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKDF}/conf-qmail
	@${REINPLACE_CMD} -e '/cat/d; s|doc/fastforward|${DOCSDIR}|g' \
		${WRKFF}/hier.c \
		${WRKDF}/hier.c
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E 's|^(.*${DOCSDIR})|// \1|g' \
		${WRKFF}/hier.c
.endif
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKFF}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKFF}/conf-ld
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKDF}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKDF}/conf-ld

do-build:
	@${MAKE} -C ${WRKDIR}/dot-forward-${DF_VER} ${ALL_TARGET}
	@${MAKE} -C ${WRKDIR}/fastforward-${FF_VER} ${ALL_TARGET}

# Do a dance to stage and keep out of resulting binaries (see r346769
# and r349241)
pre-install:
	${MKDIR} ${STAGEDIR}${QMAIL_PREFIX}/${DOCSDIR}
	@${MV} -f ${WRKFF}/conf-qmail ${WRKFF}/conf-qmail.sav
	@${ECHO_CMD} "${STAGEDIR}${QMAIL_PREFIX}" > ${WRKFF}/conf-qmail
	@cd ${WRKFF} ; ${RM} -f install instcheck install.o instcheck.o hier.o auto_home.o
	@cd ${WRKFF} ; ${MAKE_CMD} install instcheck
	@${TOUCH} ${WRKFF}/newaliases ${WRKFF}/fastforward ${WRKFF}/newinclude
	@${MV} -f ${WRKFF}/conf-qmail.sav ${WRKFF}/conf-qmail

	@${MV} -f ${WRKDF}/conf-qmail ${WRKDF}/conf-qmail.sav
	@${ECHO_CMD} "${STAGEDIR}${QMAIL_PREFIX}" > ${WRKDF}/conf-qmail
	@cd ${WRKDF} ; ${RM} -f install instcheck install.o instcheck.o hier.o auto_home.o
	@cd ${WRKDF} ; ${MAKE_CMD} install instcheck
	@${TOUCH} ${WRKDF}/dot-forward
	@${MV} -f ${WRKDF}/conf-qmail.sav ${WRKDF}/conf-qmail

do-install:
	@${MAKE} -C ${WRKDIR}/dot-forward-${DF_VER} ${INSTALL_TARGET}
	@${MAKE} -C ${WRKDIR}/fastforward-${FF_VER} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
