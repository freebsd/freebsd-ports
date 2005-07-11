# New ports collection makefile for:	queue-fix
# Date created:		2005-04-14
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	queue-fix
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.netmeridian.com/e-huss/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Repairs or generates a qmail queue structure

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

QMAIL_DIR?=	/var/qmail
PREFIX?=	${QMAIL_DIR}

OPTIONS=	BIG_TODO "Use big_todo patch" off

CONFIGURE_SCRIPT=
ALL_TARGET=

PLIST_SUB=	DOCDIR=${DOCDIR}
PLIST_FILES=	bin/queue-fix

.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DOCDIR%%/README
PLIST_DIRS+=	%%DOCDIR%%
.endif

.if (${PREFIX} == ${LOCALBASE})
DOCDIR=	share/doc/qmail/queue-fix
.else
DOCDIR=	doc/queue-fix
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_BIG_TODO)
PATCH_SITES+=		http://www.qmail.org/
PATCHFILES+=		queue-fix-todo.patch
PATCH_DIST_STRIP+=	-p1
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.post.mk>
