PORTNAME=	google-cloud-sdk-app-engine-go
DISTVERSION=	g20181102165140
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/channels/rapid/components/
DISTNAME=	${PORTNAME}-linux-x86_64-${DISTVERSION:S/^g//}

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Google Cloud SDK App Engine Go Extensions

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKDIR}/platform/google_appengine/LICENSE.golang
LICENSE_FILE_BSD3CLAUSE=	${WRKDIR}/platform/google_appengine/goroot-1.9/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	gcloud:net/google-cloud-sdk

USES=		go

do-build:
	(cd ${WRKDIR}/platform/google_appengine/goroot-1.9/src && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} \
		GOROOT_BOOTSTRAP=${LOCALBASE}/go \
		${SH} make.bash); \
	(cd ${WRKDIR}/platform/google_appengine/goroot-1.9/bin && \
		${RM} cover goapp godoc);
	(cd ${WRKDIR}/platform/google_appengine/goroot-1.9/pkg && \
		${RM} -rf bootstrap linux_amd64_appengine obj tool/linux_amd64);

do-install:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} platform ${STAGEDIR}${PREFIX}/google-cloud-sdk)
	(cd ${STAGEDIR}${PREFIX} && \
		${FIND} google-cloud-sdk/platform/google_appengine/goroot-1.9/bin -type f -exec ${CHMOD} +x {} \;);
	${MV} ${STAGEDIR}${PREFIX}/google-cloud-sdk//platform/google_appengine/goroot-1.9/bin/go-app-stager \
		${STAGEDIR}${PREFIX}/google-cloud-sdk/platform/google_appengine/;
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/google-cloud-sdk/platform/google_appengine/go-app-stager
	${MKDIR} ${STAGEDIR}${PREFIX}/google-cloud-sdk/.install
	${INSTALL_DATA} ${FILESDIR}/app-engine-go.snapshot.json ${STAGEDIR}${PREFIX}/google-cloud-sdk/.install/
	${TOUCH} ${STAGEDIR}${PREFIX}/google-cloud-sdk/.install/app-engine-go.manifest

post-install:
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s google-cloud-sdk -type f -o -type l >> ${TMPPLIST})

find-new-version:
	@(v=$$(${FETCH_CMD} -qo- ${MASTER_SITES:H:H}/components-2.json | ${SED} -nE '/${DISTNAME:S|-${DISTVERSION:S|^g||}||}/s/.*-([0-9]{14})\..*/\1/p' ); \
		[ $$v -gt ${DISTVERSION:S|^g||} ] && ${ECHO} "Found new version $$v") || ${ECHO} "No new version was found"

.include <bsd.port.mk>
