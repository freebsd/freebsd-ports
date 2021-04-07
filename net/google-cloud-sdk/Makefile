PORTNAME=	google-cloud-sdk
PORTVERSION=	331.0.0
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/
DISTNAME=	google-cloud-sdk-${PORTVERSION}-linux-x86_64

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Google Cloud SDK for Google Cloud Platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.7+

WRKSRC=		${WRKDIR}/google-cloud-sdk
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/bq \
		bin/docker-credential-gcloud \
		bin/gcloud \
		bin/git-credential-gcloud.sh \
		bin/gsutil

OPTIONS_DEFINE=		BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/gcloud
ZSH_PLIST_FILES=	share/zsh/site-functions/_gcloud

post-extract:
	@${RM} -r \
		${WRKSRC}/bin/anthoscli \
		${WRKSRC}/bin/kuberun \
		${WRKSRC}/install.bat \
		${WRKSRC}/platform/gsutil/third_party/crcmod/docs/source/make.bat \
		${WRKSRC}/platform/gsutil/third_party/rsa/doc/make.bat \
		${WRKSRC}/rpm \
		${WRKSRC}/deb \
		${WRKSRC}/lib/third_party/grpc/_cython/cygrpc.so

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' ${WRKSRC}/bin/bq ${WRKSRC}/bin/gsutil ${WRKSRC}/bin/docker-credential-gcloud ${WRKSRC}/bin/java_dev_appserver.sh ${WRKSRC}/bin/git-credential-gcloud.sh ${WRKSRC}/bin/gcloud
	@${RM} ${WRKSRC}/bin/*.bak ${WRKSRC}/bin/*.orig

do-install:
	${RM} -r ${WRKSRC}/help ${WRKSRC}/.install/.download
	( cd ${WRKSRC} ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/google-cloud-sdk )
.for x in bq docker-credential-gcloud gcloud git-credential-gcloud.sh gsutil
	${CHMOD} +x ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x}
	${RLN} ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x} \
		${STAGEDIR}${PREFIX}/bin/${x}
.endfor

post-install:
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s google-cloud-sdk -type f -o -type l >> ${TMPPLIST})

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${RLN} ${STAGEDIR}${PREFIX}/google-cloud-sdk/completion.bash.inc \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/gcloud

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${RLN} ${STAGEDIR}${PREFIX}/google-cloud-sdk/completion.zsh.inc \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_gcloud

.include <bsd.port.mk>
