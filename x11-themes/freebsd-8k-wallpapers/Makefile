# $FreeBSD$

PORTNAME=	freebsd-8k-wallpapers
DISTVERSION=	1.0
CATEGORIES=	x11-themes

MAINTAINER=	lebarondemerde@privacychain.ch
COMMENT=	Collection of simple FreeBSD wallpapers

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	lebarondemerde
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

SLAVEPORT?=	freebsd

PORTDOCS=	AUTHOR TRADEMARKS

.if ${SLAVEPORT:Mkde}
PORTDOCS+=	TRADEMARKS-KDE
DOCSDIR_REL=	share/doc/${PORTNAME}-${SLAVEPORT}
DOCSDIR=	${PREFIX}/${DOCSDIR_REL}
.endif

.if ${SLAVEPORT:Mfreebsd}
THEMEDIR_REL=	share/wallpapers/${PORTNAME}
.elif ${SLAVEPORT:Mkde}
THEMEDIR_REL=	share/wallpapers/${PORTNAME}-${SLAVEPORT}
.endif

THEMEDIR=	${PREFIX}/${THEMEDIR_REL}

.if ${SLAVEPORT:Mfreebsd}
FREEBSD_COLORS=	FreeBSD-Blue FreeBSD-Green FreeBSD-Purple \
		FreeBSD-Red FreeBSD-Yellow
.endif

do-install:
	${MKDIR} ${STAGEDIR}${THEMEDIR}

.if ${SLAVEPORT:Mfreebsd}
.  for x in ${FREEBSD_COLORS}
	( cd ${WRKSRC}/FreeBSD/${x} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THEMEDIR} )
.  endfor
.elif ${SLAVEPORT:Mkde}
	( cd ${WRKSRC}/KDE && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THEMEDIR} \
		"! -name preview.png" )
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && \
		${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR} )

.include <bsd.port.mk>
