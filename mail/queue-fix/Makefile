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

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

USE_QMAIL_RUN=	yes
MAKE_JOBS_SAFE=	yes

PREFIX?=	${QMAIL_PREFIX}

OPTIONS_DEFINE=	BIG_TODO

BIG_TODO_DESC=	Use big_todo patch

CONFIGURE_SCRIPT=
ALL_TARGET=

PLIST_FILES=	bin/queue-fix

PORTDOCS=	README

.include <bsd.port.pre.mk>

.if (${PREFIX} == ${LOCALBASE})
DOCSDIR=	${PREFIX}/share/doc/qmail/queue-fix
.else
DOCSDIR=	${PREFIX}/doc/queue-fix
.endif

.if ${PORT_OPTIONS:MBIG_TODO}
PATCH_SITES+=		http://www.qmail.org/
PATCHFILES+=		queue-fix-todo.patch
PATCH_DIST_STRIP+=	-p1
.endif

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
