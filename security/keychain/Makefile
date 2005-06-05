# New ports collection makefile for:	keychain
# Date created:		10 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	keychain
PORTVERSION=	2.5.4.1
CATEGORIES=	security
MASTER_SITES=	http://dev.gentoo.org/~agriffis/keychain/

MAINTAINER=	olive@oban.frmug.org
COMMENT=	A user-friendly front-end to ssh-agent(1)

USE_BZIP2=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400016
RUN_DEPENDS+=	ssh-agent:${PORTSDIR}/security/openssh
.endif

MAN1=		keychain.1

PLIST_FILES=	bin/keychain
.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
