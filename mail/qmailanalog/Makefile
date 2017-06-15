# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	qmailanalog
PORTVERSION=	0.70
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		http://www.emaillab.org/djb/qmailanalog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to analyze qmail-send activity

USES=		qmail:run

ALL_TARGET=	prog
INSTALL_TARGET=	setup

MANPREFIX=	${QMPREFIX}

PLIST_SUB+=	MYSUBDIR=${MYSUBDIR}

.if !defined(NOSUBDIR)
MYSUBDIR?=	qmailanalog/
.else
MYSUBDIR?=
.endif

PREFIX?=	${QMAIL_PREFIX}
NO_PREFIX_RMDIR=yes
QMPREFIX?=	${PREFIX}/${MYSUBDIR}

NO_MTREE=	yes

.include <bsd.port.pre.mk>

.if ${PREFIX} != ${QMAIL_PREFIX}
BROKEN=	Cannot Make and Install with different PREFIX or QMAIL_PREFIX
.endif

post-patch:
	@${ECHO_CMD} "${QMPREFIX}" > ${WRKSRC}/conf-home
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${REINPLACE_CMD} 's|02755|0755|g; /cat/d' ${WRKSRC}/hier.c
	@${REINPLACE_CMD} 's|^man prog|prog|g' ${WRKSRC}/Makefile

# Do a dance to stage and keep out of resulting binaries (see r346769
# and r349241)
post-build:
	@${ECHO_MSG} "===> Rebuilding DJB installer to respect STAGEDIR"
	@${MV} -f ${WRKSRC}/conf-home ${WRKSRC}/conf-home.sav
	@${ECHO_CMD} "${STAGEDIR}${QMPREFIX}" > ${WRKSRC}/conf-home
	@cd ${WRKSRC} ; ${RM} install instcheck install.o instcheck.o hier.o auto_home.o auto_home.c
	@cd ${WRKSRC} ; ${DO_MAKE_BUILD} install instcheck
	@${MV} -f ${WRKSRC}/conf-home.sav ${WRKSRC}/conf-home

post-install:
	@${MKDIR} ${STAGEDIR}${QMPREFIX}
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
