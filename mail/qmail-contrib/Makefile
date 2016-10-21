# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	qmail-contrib
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		GENTOO
DISTFILES=	dot-forward-${DF_VER}.tar.gz \
		fastforward-${FF_VER}.tar.gz

MAINTAINER=	ports@FreeBSD.org
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

pre-patch:
	@${PATCH} -d ${WRKFF} -s <${PATCHDIR}/extra-patch-newaliases

post-patch:
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKFF}/conf-qmail
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKDF}/conf-qmail
	@${REINPLACE_CMD} -e '/cat/d; s|doc/fastforward|${DOCSDIR}|g' \
		${WRKFF}/hier.c \
		${WRKDF}/hier.c
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKFF}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKFF}/conf-ld
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKDF}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKDF}/conf-ld

post-patch-DOCS-off:
	@${REINPLACE_CMD} -E 's|^(.*${DOCSDIR})|// \1|g' \
		${WRKFF}/hier.c

do-build:
	${MAKE_CMD} -C ${WRKDIR}/dot-forward-${DF_VER} ${ALL_TARGET}
	${MAKE_CMD} -C ${WRKDIR}/fastforward-${FF_VER} ${ALL_TARGET}

# Do a dance to stage and keep out of resulting binaries (see r346769
# and r349241)
post-build:
	@${ECHO_MSG} "===> Rebuilding DJB installer to respect STAGEDIR"
	${MV} -f ${WRKFF}/conf-qmail ${WRKFF}/conf-qmail.sav
	${ECHO_CMD} "${STAGEDIR}${QMAIL_PREFIX}" > ${WRKFF}/conf-qmail
	cd ${WRKFF} ; ${RM} install instcheck install.o instcheck.o hier.o auto_qmail.o auto_qmail.c
	cd ${WRKFF} ; ${DO_MAKE_BUILD} install instcheck
	${TOUCH} ${WRKFF}/newaliases ${WRKFF}/fastforward ${WRKFF}/newinclude
	${MV} -f ${WRKFF}/conf-qmail.sav ${WRKFF}/conf-qmail

	${MV} -f ${WRKDF}/conf-qmail ${WRKDF}/conf-qmail.sav
	${ECHO_CMD} "${STAGEDIR}${QMAIL_PREFIX}" > ${WRKDF}/conf-qmail
	cd ${WRKDF} ; ${RM} install instcheck install.o instcheck.o hier.o auto_qmail.o auto_qmail.c
	cd ${WRKDF} ; ${DO_MAKE_BUILD} install instcheck
	${TOUCH} ${WRKDF}/dot-forward
	${MV} -f ${WRKDF}/conf-qmail.sav ${WRKDF}/conf-qmail

do-install:
	@${MKDIR} ${STAGEDIR}${QMAIL_PREFIX}/${DOCSDIR}
	${MAKE_CMD} -C ${WRKDIR}/dot-forward-${DF_VER} ${INSTALL_TARGET}
	${MAKE_CMD} -C ${WRKDIR}/fastforward-${FF_VER} ${INSTALL_TARGET}

.include <bsd.port.mk>
