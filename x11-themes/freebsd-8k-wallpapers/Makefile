# $FreeBSD$

PORTNAME=	freebsd-8k-wallpapers
DISTVERSION=	2.1
CATEGORIES=	x11-themes
MASTER_SITES=	https://bitbucket.org/rigoletto-freebsd/freebsd-8k-wallpapers/get/

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Collection of simple FreeBSD wallpapers

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/rigoletto-freebsd-${PORTNAME}-2afc45f41224

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHOR TRADEMARKS

SLAVEPORT?=	freebsd

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
FREEBSD_COLORS=	FreeBSD-Blue FreeBSD-Green FreeBSD-Grey \
		FreeBSD-Purple FreeBSD-Red FreeBSD-Yellow
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
	( cd ${WRKSRC}/doc && \
		${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR} )

.include <bsd.port.mk>
