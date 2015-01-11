# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	portbuilder
DISTVERSION=	0.1.5.4
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://cloud.github.com/downloads/DragonSA/portbuilder/

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Concurrent FreeBSD port builder

LICENSE=	BSD2CLAUSE

DEPRECATED=	Unmaintained, please use ports-mgmt/poudriere.
EXPIRATION_DATE=	2015-03-31

USE_PYTHON=	distutils
USES=		python tar:xz

PORTDOCS=	BUGS ChangeLog COPYRIGHT README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
