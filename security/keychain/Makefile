# New ports collection makefile for:	keychain
# Date created:		10 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	keychain
PORTVERSION=	2.0.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	distributions/gentoo/distfiles

MAINTAINER=	olive@oban.frmug.org
COMMENT=	A user-friendly front-end to ssh-agent(1)

USE_BZIP2=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400016
RUN_DEPENDS=	ssh-agent:${PORTSDIR}/security/openssh
.endif

MAN1=		keychain.1

DOCS=		ChangeLog README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
