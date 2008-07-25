# New ports collection makefile for:	queue-fix
# Date created:		2005-04-14
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	queue-fix
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.netmeridian.com/e-huss/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Repairs or generates a qmail queue structure

USE_QMAIL_RUN=	yes

PREFIX?=	${QMAIL_PREFIX}

OPTIONS=	BIG_TODO "Use big_todo patch" off

CONFIGURE_SCRIPT=
ALL_TARGET=

PLIST_SUB=	DOCDIR=${DOCDIR}
PLIST_FILES=	bin/queue-fix

.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DOCDIR%%/README
PLIST_DIRS+=	%%DOCDIR%%
.endif

.include <bsd.port.pre.mk>

.if (${PREFIX} == ${LOCALBASE})
DOCDIR=	share/doc/qmail/queue-fix
.else
DOCDIR=	doc/queue-fix
.endif

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
