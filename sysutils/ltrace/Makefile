# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ltrace
PORTVERSION=	0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/sbz \
		http://www.zonov.org/${PORTNAME}/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Track runtime library calls in dynamically linked programs

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	amd64

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	DOCS

PORTDOCS=	BUGS COPYING ChangeLog README TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}

.endif

.include <bsd.port.mk>
