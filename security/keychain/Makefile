# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	keychain
PORTVERSION=	2.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.funtoo.org/archive/keychain/ \
		GENTOO/distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	User-friendly front-end to ssh-agent(1)

LICENSE=	GPLv2

USES=		gmake perl5
USE_PERL5=	build
OPTIONS_DEFINE=	DOCS
FETCH_ARGS?=	-Fpr
USE_BZIP2=	yes

MAN1=		keychain.1

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	ChangeLog README.rst

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/ssh-agent) && !exists(/usr/bin/ssh-agent)
RUN_DEPENDS+=	ssh-agent:${PORTSDIR}/security/openssh-portable
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
