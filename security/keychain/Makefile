# New ports collection makefile for:	keychain
# Date created:		10 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	keychain
PORTVERSION=	2.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A user-friendly front-end to ssh-agent(1)

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5_BUILD=	yes

MAN1=		keychain.1

PLIST_FILES=	bin/keychain

PORTDOCS=	ChangeLog README.rst

.if !exists(${LOCALBASE}/bin/ssh-agent) && !exists(/usr/bin/ssh-agent)
RUN_DEPENDS+=	ssh-agent:${PORTSDIR}/security/openssh-portable
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${PREFIX}/bin/keychain
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
