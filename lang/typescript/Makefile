PORTNAME=	typescript
DISTVERSION=	5.9.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://github.com/microsoft/TypeScript/releases/download/v${DISTVERSION}/ \
		https://registry.npmjs.org/${PORTNAME}/-/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Superset of JavaScript that compiles to JavaScript output
WWW=		https://www.typescriptlang.org/

LICENSE=	APACHE20

DEPRECATED=	New port was added without port maintainer, submitter not interested in taking it.  See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=289856 and contact mandree@ if you are willing to maintain typescript and have a track record that lets you appear suitable for maintaining a high-profile port.
EXPIRATION_DATE=2025-11-30

USES=		nodejs:run tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/package

post-patch:
	@cd ${WRKSRC}/bin && for f in *; do \
	    ${REINPLACE_CMD} -e 's|../lib|${LOCALBASE}/lib/node_modules/${PORTNAME}|g' "$$f"; \
	done

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	cd ${WRKSRC}/bin && for f in *; do \
	    case "$${f}" in *.bak) ;; *) \
	        ${INSTALL_SCRIPT} "${WRKSRC}/bin/$$f" ${STAGEDIR}${PREFIX}/bin ; \
	    esac ; \
	done
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}

.include <bsd.port.mk>
